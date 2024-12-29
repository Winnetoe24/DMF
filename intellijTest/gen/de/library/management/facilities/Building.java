package de.library.management.facilities;
import java.util.Objects;

public class Building {
    protected String name;
    protected BuildingType type;
    protected String address;
    protected int floors;
    protected int capacity;
    protected boolean isAccessible;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Building entity = (Building) o;
        return Objects.equals(name, entity.name)  && Objects.equals(type, entity.type)  && Objects.equals(address, entity.address)  && Objects.equals(floors, entity.floors)  && Objects.equals(capacity, entity.capacity)  && Objects.equals(isAccessible, entity.isAccessible) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, type, address, floors, capacity, isAccessible);
    }
}