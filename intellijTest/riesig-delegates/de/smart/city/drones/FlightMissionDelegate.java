package de.smart.city.drones;

import java.time.LocalDateTime;

/**
 * Delegate von FlightMission * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FlightMissionDelegate {
    static {
        FlightMission.delegate = new FlightMissionDelegate();
    }

}