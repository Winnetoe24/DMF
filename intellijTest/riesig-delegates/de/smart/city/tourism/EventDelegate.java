package de.smart.city.tourism;

import java.time.LocalDateTime;

/**
 * Delegate von Event * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EventDelegate {
    static {
        Event.delegate = new EventDelegate();
    }

}