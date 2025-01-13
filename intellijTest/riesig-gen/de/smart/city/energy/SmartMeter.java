package de.smart.city.energy;

import java.time.LocalDateTime;
import java.util.Objects;

public class SmartMeter {
    protected static SmartMeterDelegate delegate;
    protected String meterId;
    protected ConsumptionPattern pattern;
    protected double currentReading;
    protected double peakDemand;
    protected LocalDateTime lastReadingTime;
    protected boolean isOnline;



    public String getMeterId() {
        return this.meterId;
    }

    public void setMeterId(String meterId) {
        this.meterId = meterId;
    }

    public ConsumptionPattern getPattern() {
        return this.pattern;
    }

    public void setPattern(ConsumptionPattern pattern) {
        this.pattern = pattern;
    }

    public double getCurrentReading() {
        return this.currentReading;
    }

    public void setCurrentReading(double currentReading) {
        this.currentReading = currentReading;
    }

    public double getPeakDemand() {
        return this.peakDemand;
    }

    public void setPeakDemand(double peakDemand) {
        this.peakDemand = peakDemand;
    }

    public LocalDateTime getLastReadingTime() {
        return this.lastReadingTime;
    }

    public void setLastReadingTime(LocalDateTime lastReadingTime) {
        this.lastReadingTime = lastReadingTime;
    }

    public boolean getIsOnline() {
        return this.isOnline;
    }

    public void setIsOnline(boolean isOnline) {
        this.isOnline = isOnline;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SmartMeter entity = (SmartMeter) o;
        return Objects.equals(meterId, entity.meterId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(meterId);
    }
}