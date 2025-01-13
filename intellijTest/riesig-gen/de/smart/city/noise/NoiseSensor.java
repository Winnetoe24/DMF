package de.smart.city.noise;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class NoiseSensor extends Asset {
    protected static NoiseSensorDelegate delegate;
    protected NoiseSource sources;
    protected NoiseLevel currentLevel;
    protected double averageReading;
    protected LocalDateTime lastPeak;
    protected boolean needsCalibration;



    public NoiseSource getSources() {
        return this.sources;
    }

    public void setSources(NoiseSource sources) {
        this.sources = sources;
    }

    public NoiseLevel getCurrentLevel() {
        return this.currentLevel;
    }

    public void setCurrentLevel(NoiseLevel currentLevel) {
        this.currentLevel = currentLevel;
    }

    public double getAverageReading() {
        return this.averageReading;
    }

    public void setAverageReading(double averageReading) {
        this.averageReading = averageReading;
    }

    public LocalDateTime getLastPeak() {
        return this.lastPeak;
    }

    public void setLastPeak(LocalDateTime lastPeak) {
        this.lastPeak = lastPeak;
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
        NoiseSensor entity = (NoiseSensor) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}