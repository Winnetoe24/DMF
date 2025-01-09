package de.library.management.finance;

import java.time.LocalDate;

/**
 * Delegate von InvoiceDetails * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class InvoiceDetailsDelegate {
    static {
        InvoiceDetails.delegate = new InvoiceDetailsDelegate();
    }

}