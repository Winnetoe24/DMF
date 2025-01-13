package de.smart.city.bathrooms;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDateTime;

/**
 * Delegate von PublicBathroom * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PublicBathroomDelegate {
    static {
        PublicBathroom.delegate = new PublicBathroomDelegate();
    }

}