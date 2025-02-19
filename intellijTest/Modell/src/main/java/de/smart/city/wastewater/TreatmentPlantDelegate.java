package de.smart.city.wastewater;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von TreatmentPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TreatmentPlantDelegate {
    static {
        TreatmentPlant.delegate = new TreatmentPlantDelegate();
    }

}