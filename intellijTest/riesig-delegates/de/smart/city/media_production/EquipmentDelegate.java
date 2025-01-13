package de.smart.city.media_production;

/**
 * Delegate von Equipment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EquipmentDelegate {
    static {
        Equipment.delegate = new EquipmentDelegate();
    }

}