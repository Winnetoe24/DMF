package de.smart.city.water;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von WaterTreatmentPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WaterTreatmentPlantDelegate {
    static {
        WaterTreatmentPlant.delegate = new WaterTreatmentPlantDelegate();
    }

}