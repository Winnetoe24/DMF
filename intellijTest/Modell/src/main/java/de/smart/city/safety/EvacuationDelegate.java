package de.smart.city.safety;

import java.time.LocalDateTime;

/**
 * Delegate von Evacuation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EvacuationDelegate {
    static {
        Evacuation.delegate = new EvacuationDelegate();
    }

}