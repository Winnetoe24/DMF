package de.smart.city.safety;

import java.time.LocalDateTime;

/**
 * Delegate von SafetyIncident * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SafetyIncidentDelegate {
    static {
        SafetyIncident.delegate = new SafetyIncidentDelegate();
    }

}