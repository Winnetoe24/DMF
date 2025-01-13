package de.smart.city.lighting;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class StreetLight extends Asset {
    protected static StreetLightDelegate delegate;
    protected LightType type;
    protected BrightnessLevel brightness;
    protected double energyConsumption;
    protected boolean hasMotionSensor;



    public LightType getType() {
        return this.type;
    }

    public void setType(LightType type) {
        this.type = type;
    }

    public BrightnessLevel getBrightness() {
        return this.brightness;
    }

    public void setBrightness(BrightnessLevel brightness) {
        this.brightness = brightness;
    }

    public double getEnergyConsumption() {
        return this.energyConsumption;
    }

    public void setEnergyConsumption(double energyConsumption) {
        this.energyConsumption = energyConsumption;
    }

    public boolean getHasMotionSensor() {
        return this.hasMotionSensor;
    }

    public void setHasMotionSensor(boolean hasMotionSensor) {
        this.hasMotionSensor = hasMotionSensor;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        StreetLight entity = (StreetLight) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}