package de.smart.city.sports;

import java.time.LocalDate;

/**
 * Delegate von Tournament * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TournamentDelegate {
    static {
        Tournament.delegate = new TournamentDelegate();
    }

}