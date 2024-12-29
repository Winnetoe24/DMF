package de.library.management.facilities;

import de.library.management.users.User;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Objects;

public class RoomBooking {
    protected Room room;
    protected User user;
    protected LocalDate bookingDate;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected int numberOfPeople;
    protected String purpose;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RoomBooking entity = (RoomBooking) o;
        return Objects.equals(room, entity.room)  && Objects.equals(user, entity.user)  && Objects.equals(bookingDate, entity.bookingDate)  && Objects.equals(startTime, entity.startTime)  && Objects.equals(endTime, entity.endTime)  && Objects.equals(numberOfPeople, entity.numberOfPeople)  && Objects.equals(purpose, entity.purpose) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(room, user, bookingDate, startTime, endTime, numberOfPeople, purpose);
    }
}