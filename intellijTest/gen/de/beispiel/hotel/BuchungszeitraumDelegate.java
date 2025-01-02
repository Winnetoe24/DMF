package de.beispiel.hotel;

import java.time.LocalDateTime;

/**
 * Delegate von Buchungszeitraum * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BuchungszeitraumDelegate {
    static {
        Buchungszeitraum.delegate = new BuchungszeitraumDelegate();
    }
    /**
     * Kommentar über Funktion
     **/
    @Override
    public Zimmer getZimmer(Buchungszeitraum caller, Hotel hotel){
        return null;
    }

    @Override
    public LocalDateTime startPunkt(Buchungszeitraum caller){
        return null;
    }

    @Override
    public LocalDateTime endPunkt(Buchungszeitraum caller){
        return null;
    }

    @Override
    public boolean contains(Buchungszeitraum caller, LocalDateTime zeitpunkt){
        return false;
    }
}