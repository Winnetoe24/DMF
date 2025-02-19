package de.smart.city.signage;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von DigitalSign * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DigitalSignDelegate {
    static {
        DigitalSign.delegate = new DigitalSignDelegate();
    }

}