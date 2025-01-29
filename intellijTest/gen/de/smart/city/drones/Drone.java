package de.smart.city.drones;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Drone extends Asset {
    protected static DroneDelegate delegate;
    protected DroneType type;
    protected FlightStatus flightStatus;
    protected double batteryLevel;
    protected double maxAltitude;
    protected double range;



    public DroneType getType() {
        return this.type;
    }

    public void setType(DroneType type) {
        this.type = type;
    }

    public FlightStatus getFlightStatus() {
        return this.flightStatus;
    }

    public void setFlightStatus(FlightStatus flightStatus) {
        this.flightStatus = flightStatus;
    }

    public double getBatteryLevel() {
        return this.batteryLevel;
    }

    public void setBatteryLevel(double batteryLevel) {
        this.batteryLevel = batteryLevel;
    }

    public double getMaxAltitude() {
        return this.maxAltitude;
    }

    public void setMaxAltitude(double maxAltitude) {
        this.maxAltitude = maxAltitude;
    }

    public double getRange() {
        return this.range;
    }

    public void setRange(double range) {
        this.range = range;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Drone entity = (Drone) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}