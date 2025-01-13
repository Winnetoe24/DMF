package de.smart.city.library;

import java.time.LocalDate;

/**
 * Delegate von LibraryMember * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LibraryMemberDelegate {
    static {
        LibraryMember.delegate = new LibraryMemberDelegate();
    }

}