package de.beispiel.hotel;

import java.time.LocalDateTime;

/**
 * Das ist ein Kommentar über einem Struct
 * Alle Kommentare können mehrere Zeilen beinhalten
 **/
public class Buchungszeitraum implements de.beispiel.hotel.Zeitraum {
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

    @Override
    public boolean contains(LocalDateTime zeitpunkt) {
        return false;
    }

    @Override
    public LocalDateTime start() {
        return null;
    }

    @Override
    public LocalDateTime end() {
        return null;
    }
}