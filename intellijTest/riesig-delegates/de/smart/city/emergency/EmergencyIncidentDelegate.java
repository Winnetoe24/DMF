package de.smart.city.emergency;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von EmergencyIncident * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EmergencyIncidentDelegate {
    static {
        EmergencyIncident.delegate = new EmergencyIncidentDelegate();
    }

}