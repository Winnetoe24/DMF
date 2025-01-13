package de.smart.city.transportation;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Vehicle * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VehicleDelegate {
    static {
        Vehicle.delegate = new VehicleDelegate();
    }

}