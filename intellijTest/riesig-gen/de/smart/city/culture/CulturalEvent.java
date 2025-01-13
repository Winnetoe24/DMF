package de.smart.city.culture;

import java.time.LocalDateTime;
import java.util.Objects;

public class CulturalEvent {
    protected static CulturalEventDelegate delegate;
    protected String eventId;
    protected EventCategory category;
    protected TicketInfo ticketing;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String curator;



    public String getEventId() {
        return this.eventId;
    }

    public void setEventId(String eventId) {
        this.eventId = eventId;
    }

    public EventCategory getCategory() {
        return this.category;
    }

    public void setCategory(EventCategory category) {
        this.category = category;
    }

    public TicketInfo getTicketing() {
        return this.ticketing;
    }

    public void setTicketing(TicketInfo ticketing) {
        this.ticketing = ticketing;
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

    public String getCurator() {
        return this.curator;
    }

    public void setCurator(String curator) {
        this.curator = curator;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        CulturalEvent entity = (CulturalEvent) o;
        return Objects.equals(eventId, entity.eventId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(eventId);
    }
}