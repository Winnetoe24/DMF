package de.smart.city.markets;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDateTime;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Market * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MarketDelegate {
    static {
        Market.delegate = new MarketDelegate();
    }

}