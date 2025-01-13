package de.smart.city.weather;

import java.time.LocalDateTime;

/**
 * Delegate von WeatherAlert * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WeatherAlertDelegate {
    static {
        WeatherAlert.delegate = new WeatherAlertDelegate();
    }

}