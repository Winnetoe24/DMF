package de.library.management.lending;

import de.library.management.users.User;
import de.library.management.media.MediaItem;
import java.time.LocalDate;

/**
 * Delegate von Reservation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ReservationDelegate {
    static {
        Reservation.delegate = new ReservationDelegate();
    }

}