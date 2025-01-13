package de.smart.city.drones;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Drone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DroneDelegate {
    static {
        Drone.delegate = new DroneDelegate();
    }

}