package de.smart.city.research_facilities;

import java.time.LocalDateTime;

/**
 * Delegate von AccessCredential * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AccessCredentialDelegate {
    static {
        AccessCredential.delegate = new AccessCredentialDelegate();
    }

}