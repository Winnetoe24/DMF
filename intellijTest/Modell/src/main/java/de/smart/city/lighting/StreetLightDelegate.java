package de.smart.city.lighting;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von StreetLight * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class StreetLightDelegate {
    static {
        StreetLight.delegate = new StreetLightDelegate();
    }

}