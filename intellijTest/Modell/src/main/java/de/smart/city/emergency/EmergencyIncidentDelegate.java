package de.smart.city.emergency;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDateTime;

/**
 * Delegate von EmergencyIncident * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EmergencyIncidentDelegate {
    static {
        EmergencyIncident.delegate = new EmergencyIncidentDelegate();
    }

}