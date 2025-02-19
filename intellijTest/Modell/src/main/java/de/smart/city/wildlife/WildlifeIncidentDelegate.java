package de.smart.city.wildlife;

import java.time.LocalDateTime;

/**
 * Delegate von WildlifeIncident * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WildlifeIncidentDelegate {
    static {
        WildlifeIncident.delegate = new WildlifeIncidentDelegate();
    }

}