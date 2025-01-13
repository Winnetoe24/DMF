package de.smart.city.environment;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
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