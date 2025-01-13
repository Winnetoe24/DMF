package de.smart.city.lighting;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von StreetLight * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class StreetLightDelegate {
    static {
        StreetLight.delegate = new StreetLightDelegate();
    }

}