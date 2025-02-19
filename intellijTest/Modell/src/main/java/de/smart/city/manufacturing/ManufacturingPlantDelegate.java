package de.smart.city.manufacturing;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von ManufacturingPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ManufacturingPlantDelegate {
    static {
        ManufacturingPlant.delegate = new ManufacturingPlantDelegate();
    }

}