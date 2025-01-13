package de.smart.city.signage;

import java.time.LocalDateTime;

/**
 * Delegate von SignContent * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SignContentDelegate {
    static {
        SignContent.delegate = new SignContentDelegate();
    }

}