package de.smart.city.citizens;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Citizen * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CitizenDelegate {
    static {
        Citizen.delegate = new CitizenDelegate();
    }

}