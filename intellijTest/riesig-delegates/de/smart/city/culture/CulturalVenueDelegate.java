package de.smart.city.culture;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von CulturalVenue * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CulturalVenueDelegate {
    static {
        CulturalVenue.delegate = new CulturalVenueDelegate();
    }

}