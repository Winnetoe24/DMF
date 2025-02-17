package de.alex.brand.klein;

/**
 * Delegate von Holla * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class HollaDelegate {
    static {
        Holla.delegate = new HollaDelegate();
    }

}