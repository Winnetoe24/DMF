package de.smart.city.bathrooms;

import java.time.LocalDateTime;

/**
 * Delegate von MaintenanceTicket * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MaintenanceTicketDelegate {
    static {
        MaintenanceTicket.delegate = new MaintenanceTicketDelegate();
    }

}