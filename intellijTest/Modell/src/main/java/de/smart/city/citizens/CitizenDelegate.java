package de.smart.city.citizens;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;

/**
 * Delegate von Citizen * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CitizenDelegate {
    static {
        Citizen.delegate = new CitizenDelegate();
    }

}