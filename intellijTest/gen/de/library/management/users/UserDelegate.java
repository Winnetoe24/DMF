package de.library.management.users;

import java.time.LocalDate;

/**
 * Delegate von User * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class UserDelegate {
    static {
        User.delegate = new UserDelegate();
    }

}