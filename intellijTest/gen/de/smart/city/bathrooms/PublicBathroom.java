package de.smart.city.bathrooms;

import de.smart.city.infrastructure.Asset;
import java.time.LocalDateTime;
import java.util.Objects;

public class PublicBathroom extends Asset {
    protected static PublicBathroomDelegate delegate;
    protected BathroomType type;
    protected CleaningStatus cleaningStatus;
    protected boolean isOccupied;
    protected LocalDateTime lastCleaning;
    protected boolean hasChangingTable;



    public BathroomType getType() {
        return this.type;
    }

    public void setType(BathroomType type) {
        this.type = type;
    }

    public CleaningStatus getCleaningStatus() {
        return this.cleaningStatus;
    }

    public void setCleaningStatus(CleaningStatus cleaningStatus) {
        this.cleaningStatus = cleaningStatus;
    }

    public boolean getIsOccupied() {
        return this.isOccupied;
    }

    public void setIsOccupied(boolean isOccupied) {
        this.isOccupied = isOccupied;
    }

    public LocalDateTime getLastCleaning() {
        return this.lastCleaning;
    }

    public void setLastCleaning(LocalDateTime lastCleaning) {
        this.lastCleaning = lastCleaning;
    }

    public boolean getHasChangingTable() {
        return this.hasChangingTable;
    }

    public void setHasChangingTable(boolean hasChangingTable) {
        this.hasChangingTable = hasChangingTable;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PublicBathroom entity = (PublicBathroom) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}