package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;

/**
 * Delegate von Transaction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TransactionDelegate {
    static {
        Transaction.delegate = new TransactionDelegate();
    }

}