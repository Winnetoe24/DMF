package de.smart.city.sports;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class SportsFacility extends Asset {
    protected static SportsFacilityDelegate delegate;
    protected FacilityType type;
    protected int spectatorCapacity;
    protected boolean hasFloodlights;
    protected boolean isIndoor;



    public FacilityType getType() {
        return this.type;
    }

    public void setType(FacilityType type) {
        this.type = type;
    }

    public int getSpectatorCapacity() {
        return this.spectatorCapacity;
    }

    public void setSpectatorCapacity(int spectatorCapacity) {
        this.spectatorCapacity = spectatorCapacity;
    }

    public boolean getHasFloodlights() {
        return this.hasFloodlights;
    }

    public void setHasFloodlights(boolean hasFloodlights) {
        this.hasFloodlights = hasFloodlights;
    }

    public boolean getIsIndoor() {
        return this.isIndoor;
    }

    public void setIsIndoor(boolean isIndoor) {
        this.isIndoor = isIndoor;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SportsFacility entity = (SportsFacility) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}