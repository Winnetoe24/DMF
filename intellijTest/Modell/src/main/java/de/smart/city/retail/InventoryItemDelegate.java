package de.smart.city.retail;

/**
 * Delegate von InventoryItem * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class InventoryItemDelegate {
    static {
        InventoryItem.delegate = new InventoryItemDelegate();
    }

}