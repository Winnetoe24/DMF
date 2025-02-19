package de.smart.city.emergency;

import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von EmergencyTeam * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EmergencyTeamDelegate {
    static {
        EmergencyTeam.delegate = new EmergencyTeamDelegate();
    }

}