package de.smart.city.elevators;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Elevator extends Asset {
    protected static ElevatorDelegate delegate;
    protected ElevatorType type;
    protected OperationalStatus operationalStatus;
    protected int capacity;
    protected int currentFloor;
    protected int totalFloors;



    public ElevatorType getType() {
        return this.type;
    }

    public void setType(ElevatorType type) {
        this.type = type;
    }

    public OperationalStatus getOperationalStatus() {
        return this.operationalStatus;
    }

    public void setOperationalStatus(OperationalStatus operationalStatus) {
        this.operationalStatus = operationalStatus;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCurrentFloor() {
        return this.currentFloor;
    }

    public void setCurrentFloor(int currentFloor) {
        this.currentFloor = currentFloor;
    }

    public int getTotalFloors() {
        return this.totalFloors;
    }

    public void setTotalFloors(int totalFloors) {
        this.totalFloors = totalFloors;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Elevator entity = (Elevator) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}