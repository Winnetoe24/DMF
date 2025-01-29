package de.smart.city.environment;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 **/
public class AirQualityReading {
    protected static AirQualityReadingDelegate delegate;
    protected PollutantType pollutant;
    protected double concentration;
    protected LocalDateTime timestamp;
    protected boolean exceedsLimit;

    public boolean requiresAlert(){
        return delegate.requiresAlert(this);
    }

    public PollutantType getPollutant() {
        return this.pollutant;
    }

    public void setPollutant(PollutantType pollutant) {
        this.pollutant = pollutant;
    }
    public double getConcentration() {
        return this.concentration;
    }

    public void setConcentration(double concentration) {
        this.concentration = concentration;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public boolean getExceedsLimit() {
        return this.exceedsLimit;
    }

    public void setExceedsLimit(boolean exceedsLimit) {
        this.exceedsLimit = exceedsLimit;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AirQualityReading entity = (AirQualityReading) o;
        return Objects.equals(concentration, entity.concentration)  && Objects.equals(timestamp, entity.timestamp)  && Objects.equals(exceedsLimit, entity.exceedsLimit)  && Objects.equals(pollutant, entity.pollutant) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(concentration, timestamp, exceedsLimit, pollutant);
    }
}