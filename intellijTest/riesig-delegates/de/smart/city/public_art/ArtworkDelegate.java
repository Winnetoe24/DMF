package de.smart.city.public_art;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Artwork * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ArtworkDelegate {
    static {
        Artwork.delegate = new ArtworkDelegate();
    }

}