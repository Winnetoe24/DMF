package de.beispiel.hotel;

import java.time.LocalDateTime;
import java.util.Objects;

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

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Buchungszeitraum entity = (Buchungszeitraum) o;
        return Objects.equals(zimmernummer, entity.zimmernummer)  && Objects.equals(start, entity.start)  && Objects.equals(end, entity.end) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(zimmernummer, start, end);
    }
}