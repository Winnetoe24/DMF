package de.smart.city.library;

import java.time.LocalDateTime;

/**
 * Delegate von LoanTransaction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LoanTransactionDelegate {
    static {
        LoanTransaction.delegate = new LoanTransactionDelegate();
    }

}