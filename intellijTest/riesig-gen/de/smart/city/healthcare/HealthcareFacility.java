package de.smart.city.healthcare;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class HealthcareFacility extends Asset {
    protected static HealthcareFacilityDelegate delegate;
    protected FacilityType type;
    protected int bedCapacity;
    protected int currentOccupancy;
    protected boolean hasEmergencyUnit;



    public FacilityType getType() {
        return this.type;
    }

    public void setType(FacilityType type) {
        this.type = type;
    }

    public int getBedCapacity() {
        return this.bedCapacity;
    }

    public void setBedCapacity(int bedCapacity) {
        this.bedCapacity = bedCapacity;
    }

    public int getCurrentOccupancy() {
        return this.currentOccupancy;
    }

    public void setCurrentOccupancy(int currentOccupancy) {
        this.currentOccupancy = currentOccupancy;
    }

    public boolean getHasEmergencyUnit() {
        return this.hasEmergencyUnit;
    }

    public void setHasEmergencyUnit(boolean hasEmergencyUnit) {
        this.hasEmergencyUnit = hasEmergencyUnit;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        HealthcareFacility entity = (HealthcareFacility) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}