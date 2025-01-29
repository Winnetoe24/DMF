package de.smart.city.waste;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.GeoLocation;
import java.util.Objects;

public class WasteCollection {
    protected static WasteCollectionDelegate delegate;
    protected String collectionId;
    protected WasteType type;
    protected GeoLocation location;
    protected LocalDateTime scheduledTime;
    protected double estimatedVolume;
    protected boolean isCompleted;



    public String getCollectionId() {
        return this.collectionId;
    }

    public void setCollectionId(String collectionId) {
        this.collectionId = collectionId;
    }

    public WasteType getType() {
        return this.type;
    }

    public void setType(WasteType type) {
        this.type = type;
    }

    public GeoLocation getLocation() {
        return this.location;
    }

    public void setLocation(GeoLocation location) {
        this.location = location;
    }

    public LocalDateTime getScheduledTime() {
        return this.scheduledTime;
    }

    public void setScheduledTime(LocalDateTime scheduledTime) {
        this.scheduledTime = scheduledTime;
    }

    public double getEstimatedVolume() {
        return this.estimatedVolume;
    }

    public void setEstimatedVolume(double estimatedVolume) {
        this.estimatedVolume = estimatedVolume;
    }

    public boolean getIsCompleted() {
        return this.isCompleted;
    }

    public void setIsCompleted(boolean isCompleted) {
        this.isCompleted = isCompleted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WasteCollection entity = (WasteCollection) o;
        return Objects.equals(collectionId, entity.collectionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(collectionId);
    }
}