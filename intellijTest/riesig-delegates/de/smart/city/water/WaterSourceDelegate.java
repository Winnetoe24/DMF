package de.smart.city.water;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von WaterSource * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WaterSourceDelegate {
    static {
        WaterSource.delegate = new WaterSourceDelegate();
    }

}