package de.library.management.lending;

import java.time.LocalDate;
import de.library.management.users.User;
import de.library.management.media.MediaItem;
import java.util.Objects;

public class Reservation {
    protected static ReservationDelegate delegate;
    protected User user;
    protected MediaItem item;
    protected LocalDate reservationDate;
    protected LocalDate validUntil;
    protected boolean isActive;



    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public MediaItem getItem() {
        return this.item;
    }

    public void setItem(MediaItem item) {
        this.item = item;
    }

    public LocalDate getReservationDate() {
        return this.reservationDate;
    }

    public void setReservationDate(LocalDate reservationDate) {
        this.reservationDate = reservationDate;
    }

    public LocalDate getValidUntil() {
        return this.validUntil;
    }

    public void setValidUntil(LocalDate validUntil) {
        this.validUntil = validUntil;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Reservation entity = (Reservation) o;
        return Objects.equals(user, entity.user)  && Objects.equals(item, entity.item)  && Objects.equals(reservationDate, entity.reservationDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, item, reservationDate);
    }
}