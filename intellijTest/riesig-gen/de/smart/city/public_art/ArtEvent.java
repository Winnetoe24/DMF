package de.smart.city.public_art;

import java.time.LocalDateTime;
import java.util.Objects;

public class ArtEvent {
    protected static ArtEventDelegate delegate;
    protected String eventId;
    protected Artwork artwork;
    protected String eventType;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected int attendees;



    public String getEventId() {
        return this.eventId;
    }

    public void setEventId(String eventId) {
        this.eventId = eventId;
    }

    public Artwork getArtwork() {
        return this.artwork;
    }

    public void setArtwork(Artwork artwork) {
        this.artwork = artwork;
    }

    public String getEventType() {
        return this.eventType;
    }

    public void setEventType(String eventType) {
        this.eventType = eventType;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getEndTime() {
        return this.endTime;
    }

    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    public int getAttendees() {
        return this.attendees;
    }

    public void setAttendees(int attendees) {
        this.attendees = attendees;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ArtEvent entity = (ArtEvent) o;
        return Objects.equals(eventId, entity.eventId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(eventId);
    }
}