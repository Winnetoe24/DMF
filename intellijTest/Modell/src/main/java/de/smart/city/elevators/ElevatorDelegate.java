package de.smart.city.elevators;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Elevator * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ElevatorDelegate {
    static {
        Elevator.delegate = new ElevatorDelegate();
    }

}