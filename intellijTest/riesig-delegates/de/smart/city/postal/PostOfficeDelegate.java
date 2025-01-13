package de.smart.city.postal;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von PostOffice * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PostOfficeDelegate {
    static {
        PostOffice.delegate = new PostOfficeDelegate();
    }

}