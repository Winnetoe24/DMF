package de.smart.city.drones;

import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;

/**
 * Delegate von Drone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DroneDelegate {
    static {
        Drone.delegate = new DroneDelegate();
    }

}