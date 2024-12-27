package de.library.management.facilities;
import java.util.Objects;

public class Room {
    protected Building building;
    protected RoomType type;
    protected String roomNumber;
    protected int capacity;
    protected boolean hasNetworkAccess;
    protected boolean requiresReservation;
    protected String specialEquipment;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Room entity = (Room) o;
        return Objects.equals(building, entity.building)  && Objects.equals(type, entity.type)  && Objects.equals(roomNumber, entity.roomNumber)  && Objects.equals(capacity, entity.capacity)  && Objects.equals(hasNetworkAccess, entity.hasNetworkAccess)  && Objects.equals(requiresReservation, entity.requiresReservation)  && Objects.equals(specialEquipment, entity.specialEquipment) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(building, type, roomNumber, capacity, hasNetworkAccess, requiresReservation, specialEquipment);
    }
}