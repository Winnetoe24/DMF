package de.smart.city.elevators;

import java.time.LocalDateTime;

/**
 * Delegate von MaintenanceLog * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MaintenanceLogDelegate {
    static {
        MaintenanceLog.delegate = new MaintenanceLogDelegate();
    }

}