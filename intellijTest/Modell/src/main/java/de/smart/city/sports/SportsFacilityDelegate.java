package de.smart.city.sports;

import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;

/**
 * Delegate von SportsFacility * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SportsFacilityDelegate {
    static {
        SportsFacility.delegate = new SportsFacilityDelegate();
    }

}