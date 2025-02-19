package de.smart.city.transit_payment;

import java.time.LocalDateTime;

/**
 * Delegate von FareTransaction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FareTransactionDelegate {
    static {
        FareTransaction.delegate = new FareTransactionDelegate();
    }

}