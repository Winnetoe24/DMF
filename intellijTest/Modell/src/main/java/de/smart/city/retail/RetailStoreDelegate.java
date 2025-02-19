package de.smart.city.retail;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von RetailStore * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RetailStoreDelegate {
    static {
        RetailStore.delegate = new RetailStoreDelegate();
    }

}