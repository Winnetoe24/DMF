package de.library.management.facilities;
import java.util.Objects;

public class Room {
    protected static RoomDelegate delegate;
    protected Building building;
    protected RoomType type;
    protected String roomNumber;
    protected int capacity;
    protected boolean hasNetworkAccess;
    protected boolean requiresReservation;
    protected String specialEquipment;



    public Building getBuilding() {
        return this.building;
    }

    public void setBuilding(Building building) {
        this.building = building;
    }

    public RoomType getType() {
        return this.type;
    }

    public void setType(RoomType type) {
        this.type = type;
    }

    public String getRoomNumber() {
        return this.roomNumber;
    }

    public void setRoomNumber(String roomNumber) {
        this.roomNumber = roomNumber;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public boolean getHasNetworkAccess() {
        return this.hasNetworkAccess;
    }

    public void setHasNetworkAccess(boolean hasNetworkAccess) {
        this.hasNetworkAccess = hasNetworkAccess;
    }

    public boolean getRequiresReservation() {
        return this.requiresReservation;
    }

    public void setRequiresReservation(boolean requiresReservation) {
        this.requiresReservation = requiresReservation;
    }

    public String getSpecialEquipment() {
        return this.specialEquipment;
    }

    public void setSpecialEquipment(String specialEquipment) {
        this.specialEquipment = specialEquipment;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Room entity = (Room) o;
        return Objects.equals(building, entity.building)  && Objects.equals(roomNumber, entity.roomNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(building, roomNumber);
    }
}