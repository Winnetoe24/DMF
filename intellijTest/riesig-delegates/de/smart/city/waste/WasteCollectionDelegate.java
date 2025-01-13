package de.smart.city.waste;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDateTime;

/**
 * Delegate von WasteCollection * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WasteCollectionDelegate {
    static {
        WasteCollection.delegate = new WasteCollectionDelegate();
    }

}