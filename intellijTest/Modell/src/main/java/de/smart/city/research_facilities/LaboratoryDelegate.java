package de.smart.city.research_facilities;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von Laboratory * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LaboratoryDelegate {
    static {
        Laboratory.delegate = new LaboratoryDelegate();
    }

}