package de.smart.city.sports;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von SportsFacility * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SportsFacilityDelegate {
    static {
        SportsFacility.delegate = new SportsFacilityDelegate();
    }

}