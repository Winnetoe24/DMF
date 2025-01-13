package de.smart.city.elevators;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von Elevator * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ElevatorDelegate {
    static {
        Elevator.delegate = new ElevatorDelegate();
    }

}