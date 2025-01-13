package de.smart.city.manufacturing;

import java.time.LocalDate;

/**
 * Delegate von MaterialInventory * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MaterialInventoryDelegate {
    static {
        MaterialInventory.delegate = new MaterialInventoryDelegate();
    }

}