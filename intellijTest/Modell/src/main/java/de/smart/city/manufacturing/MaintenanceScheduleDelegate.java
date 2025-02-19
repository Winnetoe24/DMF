package de.smart.city.manufacturing;

import java.time.LocalDate;

/**
 * Delegate von MaintenanceSchedule * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MaintenanceScheduleDelegate {
    static {
        MaintenanceSchedule.delegate = new MaintenanceScheduleDelegate();
    }
    public boolean isOverdue(MaintenanceSchedule caller){
        return false;
    }
}