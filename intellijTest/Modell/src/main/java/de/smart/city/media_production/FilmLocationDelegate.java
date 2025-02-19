package de.smart.city.media_production;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von FilmLocation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FilmLocationDelegate {
    static {
        FilmLocation.delegate = new FilmLocationDelegate();
    }

}