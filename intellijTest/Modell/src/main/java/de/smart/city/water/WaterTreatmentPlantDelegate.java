package de.smart.city.water;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von WaterTreatmentPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WaterTreatmentPlantDelegate {
    static {
        WaterTreatmentPlant.delegate = new WaterTreatmentPlantDelegate();
    }

}