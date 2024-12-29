package de.library.management.lending;

import java.time.LocalDate;
import de.library.management.users.User;
import de.library.management.media.MediaItem;
import java.util.Objects;

public class Reservation {
    protected User user;
    protected MediaItem item;
    protected LocalDate reservationDate;
    protected LocalDate validUntil;
    protected boolean isActive;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Reservation entity = (Reservation) o;
        return Objects.equals(user, entity.user)  && Objects.equals(item, entity.item)  && Objects.equals(reservationDate, entity.reservationDate)  && Objects.equals(validUntil, entity.validUntil)  && Objects.equals(isActive, entity.isActive) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, item, reservationDate, validUntil, isActive);
    }
}