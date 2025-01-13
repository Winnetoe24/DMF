package de.smart.city.transit_payment;

import java.time.LocalDate;

/**
 * Delegate von TransitCard * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TransitCardDelegate {
    static {
        TransitCard.delegate = new TransitCardDelegate();
    }

}