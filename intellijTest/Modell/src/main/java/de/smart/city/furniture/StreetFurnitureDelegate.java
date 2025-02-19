package de.smart.city.furniture;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von StreetFurniture * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class StreetFurnitureDelegate {
    static {
        StreetFurniture.delegate = new StreetFurnitureDelegate();
    }

}