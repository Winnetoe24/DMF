package de.smart.city.wastewater;

import java.time.LocalDate;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class TreatmentPlant extends Asset {
    protected static TreatmentPlantDelegate delegate;
    protected double dailyCapacity;
    protected double currentFlow;
    protected boolean isOperational;
    protected LocalDate lastInspection;



    public double getDailyCapacity() {
        return this.dailyCapacity;
    }

    public void setDailyCapacity(double dailyCapacity) {
        this.dailyCapacity = dailyCapacity;
    }

    public double getCurrentFlow() {
        return this.currentFlow;
    }

    public void setCurrentFlow(double currentFlow) {
        this.currentFlow = currentFlow;
    }

    public boolean getIsOperational() {
        return this.isOperational;
    }

    public void setIsOperational(boolean isOperational) {
        this.isOperational = isOperational;
    }

    public LocalDate getLastInspection() {
        return this.lastInspection;
    }

    public void setLastInspection(LocalDate lastInspection) {
        this.lastInspection = lastInspection;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TreatmentPlant entity = (TreatmentPlant) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}