package de.smart.city.markets;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Market * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MarketDelegate {
    static {
        Market.delegate = new MarketDelegate();
    }

}