package de.smart.city.culture;

import java.time.LocalDateTime;

/**
 * Delegate von CulturalEvent * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CulturalEventDelegate {
    static {
        CulturalEvent.delegate = new CulturalEventDelegate();
    }

}