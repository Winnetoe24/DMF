package de.library.management.employees;

import java.time.LocalDate;

/**
 * Delegate von TimeOff * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TimeOffDelegate {
    static {
        TimeOff.delegate = new TimeOffDelegate();
    }

}