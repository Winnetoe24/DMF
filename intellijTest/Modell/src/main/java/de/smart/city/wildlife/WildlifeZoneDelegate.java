package de.smart.city.wildlife;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von WildlifeZone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WildlifeZoneDelegate {
    static {
        WildlifeZone.delegate = new WildlifeZoneDelegate();
    }

}