package de.smart.city.energy;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von PowerPlant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PowerPlantDelegate {
    static {
        PowerPlant.delegate = new PowerPlantDelegate();
    }

}