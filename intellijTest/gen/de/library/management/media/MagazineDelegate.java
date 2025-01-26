package de.library.management.media;

import java.time.LocalDate;

/**
 * Delegate von Magazine * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MagazineDelegate {
    static {
        Magazine.delegate = new MagazineDelegate();
    }

}