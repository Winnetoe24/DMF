package de.library.management.facilities;

import java.time.LocalDate;

/**
 * Delegate von Equipment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EquipmentDelegate {
    static {
        Equipment.delegate = new EquipmentDelegate();
    }

}