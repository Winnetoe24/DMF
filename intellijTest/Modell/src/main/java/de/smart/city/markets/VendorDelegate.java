package de.smart.city.markets;

import java.time.LocalDate;

/**
 * Delegate von Vendor * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VendorDelegate {
    static {
        Vendor.delegate = new VendorDelegate();
    }

}