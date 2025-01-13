package de.smart.city.environment;

import java.time.LocalDateTime;

/**
 * Delegate von AirQualityReading * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AirQualityReadingDelegate {
    static {
        AirQualityReading.delegate = new AirQualityReadingDelegate();
    }
    public boolean requiresAlert(AirQualityReading caller){
        return false;
    }
}