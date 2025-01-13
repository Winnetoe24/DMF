package de.smart.city.agriculture;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Sensor extends Asset {
    protected static SensorDelegate delegate;
    protected String sensorType;
    protected double readingValue;
    protected String unit;
    protected LocalDateTime lastReading;
    protected boolean needsCalibration;



    public String getSensorType() {
        return this.sensorType;
    }

    public void setSensorType(String sensorType) {
        this.sensorType = sensorType;
    }

    public double getReadingValue() {
        return this.readingValue;
    }

    public void setReadingValue(double readingValue) {
        this.readingValue = readingValue;
    }

    public String getUnit() {
        return this.unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public LocalDateTime getLastReading() {
        return this.lastReading;
    }

    public void setLastReading(LocalDateTime lastReading) {
        this.lastReading = lastReading;
    }

    public boolean getNeedsCalibration() {
        return this.needsCalibration;
    }

    public void setNeedsCalibration(boolean needsCalibration) {
        this.needsCalibration = needsCalibration;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Sensor entity = (Sensor) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}