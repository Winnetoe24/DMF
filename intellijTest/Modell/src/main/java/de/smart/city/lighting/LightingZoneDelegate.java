package de.smart.city.lighting;

/**
 * Delegate von LightingZone * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LightingZoneDelegate {
    static {
        LightingZone.delegate = new LightingZoneDelegate();
    }

}