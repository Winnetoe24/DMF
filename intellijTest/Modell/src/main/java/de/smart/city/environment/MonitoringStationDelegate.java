package de.smart.city.environment;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von MonitoringStation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MonitoringStationDelegate {
    static {
        MonitoringStation.delegate = new MonitoringStationDelegate();
    }

}