package de.smart.city.waste;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class RecyclingFacility extends Asset {
    protected static RecyclingFacilityDelegate delegate;
    protected double processingCapacity;
    protected double currentStorage;
    protected boolean isAcceptingWaste;



    public double getProcessingCapacity() {
        return this.processingCapacity;
    }

    public void setProcessingCapacity(double processingCapacity) {
        this.processingCapacity = processingCapacity;
    }

    public double getCurrentStorage() {
        return this.currentStorage;
    }

    public void setCurrentStorage(double currentStorage) {
        this.currentStorage = currentStorage;
    }

    public boolean getIsAcceptingWaste() {
        return this.isAcceptingWaste;
    }

    public void setIsAcceptingWaste(boolean isAcceptingWaste) {
        this.isAcceptingWaste = isAcceptingWaste;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RecyclingFacility entity = (RecyclingFacility) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}