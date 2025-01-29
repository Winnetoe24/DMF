package de.smart.city.media_production;
import java.util.Objects;

public class Equipment {
    protected static EquipmentDelegate delegate;
    protected String equipmentId;
    protected String type;
    protected String specifications;
    protected boolean requiresPermit;
    protected double powerRequirement;



    public String getEquipmentId() {
        return this.equipmentId;
    }

    public void setEquipmentId(String equipmentId) {
        this.equipmentId = equipmentId;
    }

    public String getType() {
        return this.type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getSpecifications() {
        return this.specifications;
    }

    public void setSpecifications(String specifications) {
        this.specifications = specifications;
    }

    public boolean getRequiresPermit() {
        return this.requiresPermit;
    }

    public void setRequiresPermit(boolean requiresPermit) {
        this.requiresPermit = requiresPermit;
    }

    public double getPowerRequirement() {
        return this.powerRequirement;
    }

    public void setPowerRequirement(double powerRequirement) {
        this.powerRequirement = powerRequirement;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Equipment entity = (Equipment) o;
        return Objects.equals(equipmentId, entity.equipmentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(equipmentId);
    }
}