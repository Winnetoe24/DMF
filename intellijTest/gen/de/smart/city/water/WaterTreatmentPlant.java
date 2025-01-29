package de.smart.city.water;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class WaterTreatmentPlant extends Asset {
    protected static WaterTreatmentPlantDelegate delegate;
    protected double processingCapacity;
    protected double currentThroughput;
    protected int treatmentStages;
    protected boolean isOperating;



    public double getProcessingCapacity() {
        return this.processingCapacity;
    }

    public void setProcessingCapacity(double processingCapacity) {
        this.processingCapacity = processingCapacity;
    }

    public double getCurrentThroughput() {
        return this.currentThroughput;
    }

    public void setCurrentThroughput(double currentThroughput) {
        this.currentThroughput = currentThroughput;
    }

    public int getTreatmentStages() {
        return this.treatmentStages;
    }

    public void setTreatmentStages(int treatmentStages) {
        this.treatmentStages = treatmentStages;
    }

    public boolean getIsOperating() {
        return this.isOperating;
    }

    public void setIsOperating(boolean isOperating) {
        this.isOperating = isOperating;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WaterTreatmentPlant entity = (WaterTreatmentPlant) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}