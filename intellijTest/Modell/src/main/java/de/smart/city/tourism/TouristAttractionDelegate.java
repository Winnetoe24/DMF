package de.smart.city.tourism;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von TouristAttraction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TouristAttractionDelegate {
    static {
        TouristAttraction.delegate = new TouristAttractionDelegate();
    }

}