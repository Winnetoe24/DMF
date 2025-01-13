package de.smart.city.buildings;

import java.time.LocalDateTime;

/**
 * Delegate von SmartDevice * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SmartDeviceDelegate {
    static {
        SmartDevice.delegate = new SmartDeviceDelegate();
    }

}