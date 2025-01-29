package de.library.management.facilities;

import java.time.LocalDate;
import java.time.LocalDateTime;
import de.library.management.users.User;
import java.util.Objects;

public class RoomBooking {
    protected static RoomBookingDelegate delegate;
    protected Room room;
    protected User user;
    protected LocalDate bookingDate;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected int numberOfPeople;
    protected String purpose;



    public Room getRoom() {
        return this.room;
    }

    public void setRoom(Room room) {
        this.room = room;
    }

    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public LocalDate getBookingDate() {
        return this.bookingDate;
    }

    public void setBookingDate(LocalDate bookingDate) {
        this.bookingDate = bookingDate;
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

    public int getNumberOfPeople() {
        return this.numberOfPeople;
    }

    public void setNumberOfPeople(int numberOfPeople) {
        this.numberOfPeople = numberOfPeople;
    }

    public String getPurpose() {
        return this.purpose;
    }

    public void setPurpose(String purpose) {
        this.purpose = purpose;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RoomBooking entity = (RoomBooking) o;
        return Objects.equals(room, entity.room)  && Objects.equals(bookingDate, entity.bookingDate)  && Objects.equals(startTime, entity.startTime) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(room, bookingDate, startTime);
    }
}