package de.smart.city.restaurants;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Restaurant * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RestaurantDelegate {
    static {
        Restaurant.delegate = new RestaurantDelegate();
    }

}