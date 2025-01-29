package de.smart.city.library;
import java.util.Objects;

public class StudyRoom {
    protected static StudyRoomDelegate delegate;
    protected String roomId;
    protected LibraryBranch branch;
    protected int capacity;
    protected boolean hasProjector;
    protected boolean hasWhiteboard;
    protected boolean isOccupied;



    public String getRoomId() {
        return this.roomId;
    }

    public void setRoomId(String roomId) {
        this.roomId = roomId;
    }

    public LibraryBranch getBranch() {
        return this.branch;
    }

    public void setBranch(LibraryBranch branch) {
        this.branch = branch;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public boolean getHasProjector() {
        return this.hasProjector;
    }

    public void setHasProjector(boolean hasProjector) {
        this.hasProjector = hasProjector;
    }

    public boolean getHasWhiteboard() {
        return this.hasWhiteboard;
    }

    public void setHasWhiteboard(boolean hasWhiteboard) {
        this.hasWhiteboard = hasWhiteboard;
    }

    public boolean getIsOccupied() {
        return this.isOccupied;
    }

    public void setIsOccupied(boolean isOccupied) {
        this.isOccupied = isOccupied;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        StudyRoom entity = (StudyRoom) o;
        return Objects.equals(roomId, entity.roomId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(roomId);
    }
}