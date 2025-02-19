package de.smart.city.agriculture;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDateTime;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Sensor * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SensorDelegate {
    static {
        Sensor.delegate = new SensorDelegate();
    }

}