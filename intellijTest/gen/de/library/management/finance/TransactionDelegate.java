package de.library.management.finance;

import de.library.management.users.User;
import java.time.LocalDate;

/**
 * Delegate von Transaction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TransactionDelegate {
    static {
        Transaction.delegate = new TransactionDelegate();
    }

}