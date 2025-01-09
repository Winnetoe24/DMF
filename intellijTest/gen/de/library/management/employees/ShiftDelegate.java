package de.library.management.employees;

import java.time.LocalDate;
import java.time.LocalDateTime;
import de.library.management.facilities.Building;

/**
 * Delegate von Shift * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ShiftDelegate {
    static {
        Shift.delegate = new ShiftDelegate();
    }

}