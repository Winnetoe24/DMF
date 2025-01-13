package de.smart.city.library;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class LibraryBranch extends Asset {
    protected static LibraryBranchDelegate delegate;
    protected String branchName;
    protected int capacity;
    protected int computerStations;
    protected boolean hasStudyRooms;



    public String getBranchName() {
        return this.branchName;
    }

    public void setBranchName(String branchName) {
        this.branchName = branchName;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getComputerStations() {
        return this.computerStations;
    }

    public void setComputerStations(int computerStations) {
        this.computerStations = computerStations;
    }

    public boolean getHasStudyRooms() {
        return this.hasStudyRooms;
    }

    public void setHasStudyRooms(boolean hasStudyRooms) {
        this.hasStudyRooms = hasStudyRooms;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LibraryBranch entity = (LibraryBranch) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}