package de.library.management.users;

/**
 * Delegate von Address * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AddressDelegate {
    static {
        Address.delegate = new AddressDelegate();
    }

}