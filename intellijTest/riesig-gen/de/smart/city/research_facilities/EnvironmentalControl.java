package de.smart.city.research_facilities;
import java.util.Objects;

public class EnvironmentalControl {
    protected static EnvironmentalControlDelegate delegate;
    protected String controlId;
    protected Laboratory lab;
    protected double temperature;
    protected double humidity;
    protected double pressure;
    protected double particleCount;
    protected boolean withinSpecs;



    public String getControlId() {
        return this.controlId;
    }

    public void setControlId(String controlId) {
        this.controlId = controlId;
    }

    public Laboratory getLab() {
        return this.lab;
    }

    public void setLab(Laboratory lab) {
        this.lab = lab;
    }

    public double getTemperature() {
        return this.temperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public double getHumidity() {
        return this.humidity;
    }

    public void setHumidity(double humidity) {
        this.humidity = humidity;
    }

    public double getPressure() {
        return this.pressure;
    }

    public void setPressure(double pressure) {
        this.pressure = pressure;
    }

    public double getParticleCount() {
        return this.particleCount;
    }

    public void setParticleCount(double particleCount) {
        this.particleCount = particleCount;
    }

    public boolean getWithinSpecs() {
        return this.withinSpecs;
    }

    public void setWithinSpecs(boolean withinSpecs) {
        this.withinSpecs = withinSpecs;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EnvironmentalControl entity = (EnvironmentalControl) o;
        return Objects.equals(controlId, entity.controlId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(controlId);
    }
}