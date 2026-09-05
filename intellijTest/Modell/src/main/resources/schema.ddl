create table Apfelsaft (
    l INTEGER,
    sa DATE,
    inter INTEGER,
    PRIMARY KEY(l)
);

comment on column Apfelsaft.inter is 'ref .Apfelsaft a;';

create table I (
    ID INTEGER,
    PRIMARY KEY(ID)
);

comment on column I.ID is 'Die ID jeder Instanz';

create table Apfelsaft_intMap (
    Refl INTEGER,
    Key INTEGER,
    Value INTEGER,
    PRIMARY KEY(Refl, Key)
);

comment on column Apfelsaft_intMap.Refl is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Apfelsaft_intMap.Key is 'Key der Map';
comment on column Apfelsaft_intMap.Value is 'Wert der Map';

