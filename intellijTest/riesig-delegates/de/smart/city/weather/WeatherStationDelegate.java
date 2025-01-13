package de.smart.city.weather;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von WeatherStation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class WeatherStationDelegate {
    static {
        WeatherStation.delegate = new WeatherStationDelegate();
    }

}