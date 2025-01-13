package de.smart.city.energy;

import java.time.LocalDateTime;

/**
 * Delegate von SmartMeter * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SmartMeterDelegate {
    static {
        SmartMeter.delegate = new SmartMeterDelegate();
    }

}