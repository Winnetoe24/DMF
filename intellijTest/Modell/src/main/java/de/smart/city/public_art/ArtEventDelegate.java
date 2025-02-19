package de.smart.city.public_art;

import java.time.LocalDateTime;

/**
 * Delegate von ArtEvent * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ArtEventDelegate {
    static {
        ArtEvent.delegate = new ArtEventDelegate();
    }

}