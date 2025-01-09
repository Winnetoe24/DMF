package de.library.management.lending;

import java.time.LocalDate;
import de.library.management.users.User;
import de.library.management.media.MediaItem;

/**
 * Delegate von Reservation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ReservationDelegate {
    static {
        Reservation.delegate = new ReservationDelegate();
    }

}