package de.smart.city.wildlife;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von WildlifeZone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WildlifeZoneDelegate {
    static {
        WildlifeZone.delegate = new WildlifeZoneDelegate();
    }

}