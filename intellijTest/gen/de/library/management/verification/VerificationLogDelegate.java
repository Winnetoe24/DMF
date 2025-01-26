package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.employees.Employee;

/**
 * Delegate von VerificationLog * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VerificationLogDelegate {
    static {
        VerificationLog.delegate = new VerificationLogDelegate();
    }

}