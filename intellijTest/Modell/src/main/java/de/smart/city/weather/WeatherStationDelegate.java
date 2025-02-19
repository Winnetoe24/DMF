package de.smart.city.weather;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von WeatherStation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WeatherStationDelegate {
    static {
        WeatherStation.delegate = new WeatherStationDelegate();
    }

}