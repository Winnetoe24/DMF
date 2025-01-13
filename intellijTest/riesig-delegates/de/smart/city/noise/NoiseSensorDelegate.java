package de.smart.city.noise;

import java.time.LocalDate;
import java.time.LocalDateTime;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von NoiseSensor * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class NoiseSensorDelegate {
    static {
        NoiseSensor.delegate = new NoiseSensorDelegate();
    }

}