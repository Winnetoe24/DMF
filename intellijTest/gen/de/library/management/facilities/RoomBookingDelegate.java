package de.library.management.facilities;

import de.library.management.users.User;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * Delegate von RoomBooking * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RoomBookingDelegate {
    static {
        RoomBooking.delegate = new RoomBookingDelegate();
    }

}