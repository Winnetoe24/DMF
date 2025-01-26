package de.library.management.employees;

import java.time.LocalDateTime;

/**
 * Delegate von WorkSchedule * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WorkScheduleDelegate {
    static {
        WorkSchedule.delegate = new WorkScheduleDelegate();
    }

}