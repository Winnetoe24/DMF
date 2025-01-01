package de.beispiel.hotel;

import java.time.LocalDateTime;

/**
 * Delegate von Buchungszeitraum * Wird nur initial generiert. * Methoden müssen implementiert werden. **/
public class BuchungszeitraumDelegate {
    /**
     * Kommentar über Funktion
     **/
    public Zimmer getZimmer(Buchungszeitraum caller, Hotel hotel){
        return null;
    }

    public boolean contains(Buchungszeitraum caller, LocalDateTime zeitpunkt){
        return false;
    }

    public LocalDateTime startPunkt(Buchungszeitraum caller){
        return null;
    }

    public LocalDateTime endPunkt(Buchungszeitraum caller){
        return null;
    }
}