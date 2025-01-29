package de.smart.city.tourism;

import java.time.LocalDateTime;
import java.util.Objects;

public class Event {
    protected static EventDelegate delegate;
    protected String eventId;
    protected SeasonType season;
    protected String name;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected int expectedAttendance;



    public String getEventId() {
        return this.eventId;
    }

    public void setEventId(String eventId) {
        this.eventId = eventId;
    }

    public SeasonType getSeason() {
        return this.season;
    }

    public void setSeason(SeasonType season) {
        this.season = season;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
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

    public int getExpectedAttendance() {
        return this.expectedAttendance;
    }

    public void setExpectedAttendance(int expectedAttendance) {
        this.expectedAttendance = expectedAttendance;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Event entity = (Event) o;
        return Objects.equals(eventId, entity.eventId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(eventId);
    }
}