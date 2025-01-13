package de.smart.city.urbanplanning;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Zone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ZoneDelegate {
    static {
        Zone.delegate = new ZoneDelegate();
    }

}