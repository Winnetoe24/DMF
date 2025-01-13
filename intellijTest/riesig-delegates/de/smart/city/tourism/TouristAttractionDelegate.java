package de.smart.city.tourism;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von TouristAttraction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TouristAttractionDelegate {
    static {
        TouristAttraction.delegate = new TouristAttractionDelegate();
    }

}