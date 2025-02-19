package de.smart.city.urbanplanning;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Zone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ZoneDelegate {
    static {
        Zone.delegate = new ZoneDelegate();
    }

}