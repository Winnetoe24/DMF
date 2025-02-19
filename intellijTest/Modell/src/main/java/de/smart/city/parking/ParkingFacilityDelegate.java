package de.smart.city.parking;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von ParkingFacility * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ParkingFacilityDelegate {
    static {
        ParkingFacility.delegate = new ParkingFacilityDelegate();
    }

}