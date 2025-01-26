package de.library.management.verification;

import java.time.LocalDate;

/**
 * Delegate von VerificationDocument * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VerificationDocumentDelegate {
    static {
        VerificationDocument.delegate = new VerificationDocumentDelegate();
    }

}