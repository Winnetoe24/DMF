package hibernate

import (
	"embed"
	"io"
	"strings"
	"text/template"

	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

//go:embed template/*
var tmplFiles embed.FS

type HibernateTemplate struct {
	template   *template.Template
	schema     *dmodel.Schema
	typeLookUp smodel.TypeLookUp
}

type hbmIdField struct {
	Name      string
	Column    string
	Type      string
	Generator string
}

type hbmPropertyField struct {
	Name   string
	Column string
	Type   string
}

type hbmManyToOneField struct {
	Name    string
	Columns []string
	Class   string
}

type hbmEnumField struct {
	Name      string
	Column    string
	EnumClass string
}

type hbmComponentField struct {
	Name       string
	Class      string
	Properties []hbmPropertyField
	ManyToOne  []hbmManyToOneField
	Enums      []hbmEnumField
}

type hbmCollectionField struct {
	Name           string
	TableName      string
	CollectionType string
	KeyColumn      string
	ElementColumn  string
	ElementType    string
	KeyType        string
}

type hbmEntityData struct {
	Package     string
	ClassName   string
	TableName   string
	Identifiers []hbmIdField
	Properties  []hbmPropertyField
	ManyToOne   []hbmManyToOneField
	Enums       []hbmEnumField
	Components  []hbmComponentField
	Collections []hbmCollectionField
}

var _ gbase.DMFTemplate = HibernateTemplate{}

func NewTemplate(schema dmodel.Schema, typeLookUp smodel.TypeLookUp) HibernateTemplate {
	funcMap := template.FuncMap{}
	must := template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*"))
	return HibernateTemplate{
		template:   must,
		schema:     &schema,
		typeLookUp: typeLookUp,
	}
}

func (h HibernateTemplate) GenerateStruct(writer io.Writer, element *packages.StructElement) error {
	if h.isStructReferenced(element) {
		return nil
	}
	table := h.findTable(element.Path)
	if table == nil {
		return nil
	}
	data := h.buildStructData(element, table)
	println("Generate Hibernate Struct: " + element.Path.ToString())
	return h.template.ExecuteTemplate(writer, "hbm_struct", data)
}

func (h HibernateTemplate) GenerateEntity(writer io.Writer, element *packages.EntityElement) error {
	table := h.findTable(element.Path)
	if table == nil {
		return nil
	}
	data := h.buildEntityData(element, table)
	println("Generate Hibernate Entity: " + element.Path.ToString())
	return h.template.ExecuteTemplate(writer, "hbm_entity", data)
}

func (h HibernateTemplate) GenerateEnum(_ io.Writer, _ *packages.EnumElement) error {
	return nil
}

func (h HibernateTemplate) GenerateInterface(_ io.Writer, _ *packages.InterfaceElement) error {
	return nil
}

func (h HibernateTemplate) GenerateDelegate(_ io.Writer, _ packages.PackageElement) error {
	return nil
}

func (h HibernateTemplate) GenerateDelegateInterface(_ io.Writer, _ packages.PackageElement) error {
	return nil
}

func (h HibernateTemplate) GenerateTable(_ io.Writer, _ dmodel.Table) error {
	return nil
}

func (h HibernateTemplate) GetOverrideAdapter() gbase.OverrideAdapter {
	return nil
}

func (h HibernateTemplate) buildEntityData(element *packages.EntityElement, table *dmodel.Table) hbmEntityData {
	data := hbmEntityData{
		Package:   packagePath(element.Path),
		ClassName: element.Path[len(element.Path)-1],
		TableName: table.Name,
	}

	identifierNames := make(map[string]bool)
	for _, idVar := range element.EntityIdentifier.Variablen {
		identifierNames[idVar.Name] = true
		named, ok := element.NamedElements[idVar.Name]
		if !ok {
			continue
		}
		arg, ok := named.(*packages.Argument)
		if !ok {
			continue
		}
		hibernateType := hibernateType(arg.Typ)
		data.Identifiers = append(data.Identifiers, hbmIdField{
			Name:      idVar.Name,
			Column:    idVar.Name,
			Type:      hibernateType,
			Generator: idGenerator(arg.Typ),
		})
	}

	for _, arg := range element.Argumente {
		if identifierNames[arg.Name.Name] {
			continue
		}
		data.Properties = append(data.Properties, hbmPropertyField{
			Name:   arg.Name.Name,
			Column: arg.Name.Name,
			Type:   hibernateType(arg.Typ),
		})
	}

	for _, ref := range element.Referenzen {
		if h.isEntityRef(ref) {
			colName := h.findRefColumnName(table, ref.Name.Name)
			data.ManyToOne = append(data.ManyToOne, hbmManyToOneField{
				Name:    ref.Name.Name,
				Columns: []string{colName},
				Class:   ref.Typ[len(ref.Typ)-1],
			})
		} else if h.isEnumRef(ref) {
			colName := h.findRefColumnName(table, ref.Name.Name)
			data.Enums = append(data.Enums, hbmEnumField{
				Name:      ref.Name.Name,
				Column:    colName,
				EnumClass: strings.Join(ref.Typ, "."),
			})
		} else {
			comp := h.buildComponentField(ref, table)
			if comp != nil {
				data.Components = append(data.Components, *comp)
			}
		}
	}

	data.Collections = h.buildCollectionFields(element, table)

	if len(data.Identifiers) == 0 && len(table.Columns) > 0 {
		for _, col := range table.Columns {
			if col.PrimaryKey {
				for _, arg := range element.Argumente {
					if arg.Name.Name == col.Name {
						data.Identifiers = append(data.Identifiers, hbmIdField{
							Name:   arg.Name.Name,
							Column: col.Name,
							Type:   hibernateType(arg.Typ),
						})
						break
					}
				}
			}
		}
	}

	return data
}

func (h HibernateTemplate) buildStructData(element *packages.StructElement, table *dmodel.Table) hbmEntityData {
	data := hbmEntityData{
		Package:   packagePath(element.Path),
		ClassName: element.Path[len(element.Path)-1],
		TableName: table.Name,
	}

	for _, arg := range element.Argumente {
		data.Properties = append(data.Properties, hbmPropertyField{
			Name:   arg.Name.Name,
			Column: arg.Name.Name,
			Type:   hibernateType(arg.Typ),
		})
	}

	for _, ref := range element.Referenzen {
		if h.isEntityRef(ref) {
			colName := h.findRefColumnName(table, ref.Name.Name)
			data.ManyToOne = append(data.ManyToOne, hbmManyToOneField{
				Name:    ref.Name.Name,
				Columns: []string{colName},
				Class:   ref.Typ[len(ref.Typ)-1],
			})
		} else if h.isEnumRef(ref) {
			colName := h.findRefColumnName(table, ref.Name.Name)
			data.ManyToOne = append(data.ManyToOne, hbmManyToOneField{
				Name:    ref.Name.Name,
				Columns: []string{colName},
				Class:   ref.Typ[len(ref.Typ)-1],
			})
		}
	}

	return data
}

func (h HibernateTemplate) buildComponentField(ref packages.Referenz, entityTable *dmodel.Table) *hbmComponentField {
	structPath := ref.Typ.ToString()

	structElement, ok := h.typeLookUp[structPath]
	if !ok {
		return nil
	}

	structEl, ok := structElement.(*packages.StructElement)
	if !ok {
		return nil
	}

	prefix := ref.Name.Name

	comp := &hbmComponentField{
		Name:  ref.Name.Name,
		Class: ref.Typ[len(ref.Typ)-1],
	}

	for _, arg := range structEl.Argumente {
		colName := h.findColumnByPrefix(entityTable, prefix+arg.Name.Name)
		comp.Properties = append(comp.Properties, hbmPropertyField{
			Name:   arg.Name.Name,
			Column: colName,
			Type:   hibernateType(arg.Typ),
		})
	}

	for _, innerRef := range structEl.Referenzen {
		if h.isEntityRef(innerRef) || h.isEnumRef(innerRef) {
			colName := h.findColumnByPrefix(entityTable, prefix+innerRef.Name.Name)
			if h.isEnumRef(innerRef) {
				comp.Enums = append(comp.Enums, hbmEnumField{
					Name:      innerRef.Name.Name,
					Column:    colName,
					EnumClass: strings.Join(innerRef.Typ, "."),
				})
			} else {
				comp.ManyToOne = append(comp.ManyToOne, hbmManyToOneField{
					Name:    innerRef.Name.Name,
					Columns: []string{colName},
					Class:   innerRef.Typ[len(innerRef.Typ)-1],
				})
			}
		}
	}

	return comp
}

func (h HibernateTemplate) buildCollectionFields(element *packages.EntityElement, table *dmodel.Table) []hbmCollectionField {
	var collections []hbmCollectionField

	for _, multiRef := range element.MultiReferenzen {
		joinTableName := h.findJoinTableName(table, multiRef.Name.Name)

		entry := hbmCollectionField{
			Name:      multiRef.Name.Name,
			TableName: joinTableName,
			KeyColumn: table.Name + "_ID",
		}

		switch multiRef.Typ {
		case packages.SET:
			entry.CollectionType = "set"
		case packages.LIST:
			entry.CollectionType = "list"
		case packages.MAP:
			entry.CollectionType = "map"
		}

		gen0 := multiRef.Generics[0]
		gen1 := multiRef.Generics[1]

		if gen0.PrimitivType != nil {
			entry.ElementType = hibernateType(*gen0.PrimitivType)
		} else if gen0.ModelPath != nil {
			entry.ElementType = (*gen0.ModelPath)[len(*gen0.ModelPath)-1]
		} else {
			entry.ElementType = "string"
		}

		if multiRef.Typ == packages.MAP && gen1.PrimitivType != nil {
			entry.KeyType = hibernateType(*gen1.PrimitivType)
		} else if multiRef.Typ == packages.MAP && gen1.ModelPath != nil {
			entry.KeyType = (*gen1.ModelPath)[len(*gen1.ModelPath)-1]
		} else if multiRef.Typ == packages.MAP {
			entry.KeyType = "string"
		}

		colSuffix := strings.ToUpper(multiRef.Name.Name)
		entry.ElementColumn = colSuffix
		if multiRef.Typ == packages.MAP {
			entry.KeyColumn = "MAP_KEY"
		}

		collections = append(collections, entry)
	}

	return collections
}

func (h HibernateTemplate) findTable(path base.ModelPath) *dmodel.Table {
	t, ok := h.schema.TableLookUp[path.ToString()]
	if !ok {
		return nil
	}
	return t
}

func (h HibernateTemplate) findColumnByPrefix(table *dmodel.Table, prefix string) string {
	if table == nil {
		return prefix
	}
	for _, col := range table.Columns {
		if strings.EqualFold(col.Name, prefix) {
			return col.Name
		}
	}
	for _, col := range table.Columns {
		if strings.HasPrefix(strings.ToLower(col.Name), strings.ToLower(prefix)) {
			return col.Name
		}
	}
	return prefix
}

func (h HibernateTemplate) findRefColumnName(table *dmodel.Table, refName string) string {
	for _, col := range table.Columns {
		if col.ForeignKey != nil && strings.HasPrefix(col.Name, refName) {
			return col.Name
		}
	}
	return refName + "id"
}

func (h HibernateTemplate) findJoinTableName(table *dmodel.Table, fieldName string) string {
	for _, ref := range table.TablesForElements {
		if ref.Referenzname == fieldName && ref.Table != nil {
			return ref.Table.Name
		}
	}
	return table.Name + "_" + strings.ToUpper(fieldName)
}

func (h HibernateTemplate) isEntityRef(ref packages.Referenz) bool {
	path := ref.Typ.ToString()
	elem, ok := h.typeLookUp[path]
	if !ok {
		return false
	}
	_, isEntity := elem.(*packages.EntityElement)
	return isEntity
}

func (h HibernateTemplate) isEnumRef(ref packages.Referenz) bool {
	path := ref.Typ.ToString()
	elem, ok := h.typeLookUp[path]
	if !ok {
		return false
	}
	_, isEnum := elem.(*packages.EnumElement)
	return isEnum
}

func (h HibernateTemplate) isStructReferenced(element *packages.StructElement) bool {
	elementPath := element.Path.ToString()
	for _, elem := range h.typeLookUp {
		entity, ok := elem.(*packages.EntityElement)
		if !ok {
			continue
		}
		for _, ref := range entity.Referenzen {
			if ref.Typ.ToString() == elementPath {
				return true
			}
		}
	}
	return false
}

func packagePath(path base.ModelPath) string {
	return strings.Join(path[:len(path)-1], ".")
}
