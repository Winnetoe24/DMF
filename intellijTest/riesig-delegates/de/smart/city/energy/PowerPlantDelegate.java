package de.smart.city.energy;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von PowerPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PowerPlantDelegate {
    static {
        PowerPlant.delegate = new PowerPlantDelegate();
    }

}