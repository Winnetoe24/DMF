package de.library.management.employees;

import java.time.LocalDate;

/**
 * Delegate von Performance * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PerformanceDelegate {
    static {
        Performance.delegate = new PerformanceDelegate();
    }

}