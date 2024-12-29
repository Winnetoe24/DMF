package de.beispiel.hotel;

import java.time.LocalDateTime;

/**
 * Das ist ein Kommentar über einem Struct
 * Alle Kommentare können mehrere Zeilen beinhalten
 **/
public class Buchungszeitraum implements Zeitraum {
    /**
     * Kommentar über einem Argument
     **/
    protected LocalDateTime start;
    protected LocalDateTime end;
    protected long zimmernummer;

    /**
     * Kommentar über Funktion
     **/
    public Zimmer getZimmer(Hotel hotel){
        return null;
    }

    public boolean contains(LocalDateTime zeitpunkt){
        return false;
    }

    public LocalDateTime startPunkt(){
        return null;
    }

    public LocalDateTime endPunkt(){
        return null;
    }
}