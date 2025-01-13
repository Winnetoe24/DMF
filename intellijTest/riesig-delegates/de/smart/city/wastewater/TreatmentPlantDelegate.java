package de.smart.city.wastewater;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von TreatmentPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TreatmentPlantDelegate {
    static {
        TreatmentPlant.delegate = new TreatmentPlantDelegate();
    }

}