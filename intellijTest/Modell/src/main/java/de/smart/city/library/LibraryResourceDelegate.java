package de.smart.city.library;

import java.time.LocalDate;

/**
 * Delegate von LibraryResource * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LibraryResourceDelegate {
    static {
        LibraryResource.delegate = new LibraryResourceDelegate();
    }

}