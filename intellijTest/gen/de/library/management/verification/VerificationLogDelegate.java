package de.library.management.verification;

import de.library.management.employees.Employee;
import java.time.LocalDate;

/**
 * Delegate von VerificationLog * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VerificationLogDelegate {
    static {
        VerificationLog.delegate = new VerificationLogDelegate();
    }

}