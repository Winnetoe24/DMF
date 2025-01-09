package de.library.management.facilities;
import java.util.Objects;

public class Building {
    protected static BuildingDelegate delegate;
    protected String name;
    protected BuildingType type;
    protected String address;
    protected int floors;
    protected int capacity;
    protected boolean isAccessible;



    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public BuildingType getType() {
        return this.type;
    }

    public void setType(BuildingType type) {
        this.type = type;
    }

    public String getAddress() {
        return this.address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getFloors() {
        return this.floors;
    }

    public void setFloors(int floors) {
        this.floors = floors;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public boolean getIsAccessible() {
        return this.isAccessible;
    }

    public void setIsAccessible(boolean isAccessible) {
        this.isAccessible = isAccessible;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Building entity = (Building) o;
        return Objects.equals(name, entity.name) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}