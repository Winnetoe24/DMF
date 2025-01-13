package de.smart.city.agriculture;

import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;

/**
 * Delegate von Farm * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FarmDelegate {
    static {
        Farm.delegate = new FarmDelegate();
    }

}