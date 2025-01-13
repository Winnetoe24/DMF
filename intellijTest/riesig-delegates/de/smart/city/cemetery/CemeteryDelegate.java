package de.smart.city.cemetery;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Cemetery * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CemeteryDelegate {
    static {
        Cemetery.delegate = new CemeteryDelegate();
    }

}