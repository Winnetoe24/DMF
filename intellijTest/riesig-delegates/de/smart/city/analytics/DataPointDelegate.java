package de.smart.city.analytics;

import java.time.LocalDateTime;

/**
 * Delegate von DataPoint * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DataPointDelegate {
    static {
        DataPoint.delegate = new DataPointDelegate();
    }

}