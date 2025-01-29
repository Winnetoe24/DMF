package de.smart.city.water;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class WaterSource extends Asset {
    protected static WaterSourceDelegate delegate;
    protected double capacity;
    protected double currentLevel;
    protected WaterQuality quality;
    protected double flowRate;
    protected boolean isActive;



    public double getCapacity() {
        return this.capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public double getCurrentLevel() {
        return this.currentLevel;
    }

    public void setCurrentLevel(double currentLevel) {
        this.currentLevel = currentLevel;
    }

    public WaterQuality getQuality() {
        return this.quality;
    }

    public void setQuality(WaterQuality quality) {
        this.quality = quality;
    }

    public double getFlowRate() {
        return this.flowRate;
    }

    public void setFlowRate(double flowRate) {
        this.flowRate = flowRate;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WaterSource entity = (WaterSource) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}