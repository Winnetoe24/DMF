package de.smart.city.transportation;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Vehicle extends Asset {
    protected static VehicleDelegate delegate;
    protected VehicleType type;
    protected String registrationNumber;
    protected int capacity;
    protected double currentFuelLevel;
    protected int currentPassengerCount;
    protected TransportRoute currentRoute;



    public VehicleType getType() {
        return this.type;
    }

    public void setType(VehicleType type) {
        this.type = type;
    }

    public String getRegistrationNumber() {
        return this.registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public double getCurrentFuelLevel() {
        return this.currentFuelLevel;
    }

    public void setCurrentFuelLevel(double currentFuelLevel) {
        this.currentFuelLevel = currentFuelLevel;
    }

    public int getCurrentPassengerCount() {
        return this.currentPassengerCount;
    }

    public void setCurrentPassengerCount(int currentPassengerCount) {
        this.currentPassengerCount = currentPassengerCount;
    }

    public TransportRoute getCurrentRoute() {
        return this.currentRoute;
    }

    public void setCurrentRoute(TransportRoute currentRoute) {
        this.currentRoute = currentRoute;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Vehicle entity = (Vehicle) o;
        return Objects.equals(registrationNumber, entity.registrationNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(registrationNumber);
    }
}