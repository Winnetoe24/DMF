package de.smart.city.agriculture;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDateTime;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von Sensor * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SensorDelegate {
    static {
        Sensor.delegate = new SensorDelegate();
    }

}