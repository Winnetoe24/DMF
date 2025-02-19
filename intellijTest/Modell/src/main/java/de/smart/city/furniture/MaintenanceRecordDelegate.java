package de.smart.city.furniture;

import java.time.LocalDate;

/**
 * Delegate von MaintenanceRecord * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MaintenanceRecordDelegate {
    static {
        MaintenanceRecord.delegate = new MaintenanceRecordDelegate();
    }

}