package de.library.management.media;

import java.time.LocalDate;

/**
 * Delegate von Book * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BookDelegate {
    static {
        Book.delegate = new BookDelegate();
    }

}