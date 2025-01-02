package de.beispiel.hotel;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 * Das ist ein Kommentar über einem Struct
 * Alle Kommentare können mehrere Zeilen beinhalten
 **/
public class Buchungszeitraum implements Zeitraum {
    protected static BuchungszeitraumDelegate delegate;
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
        return delegate(this, hotel);
    }

    public boolean contains(LocalDateTime zeitpunkt){
        return delegate(this, zeitpunkt);
    }

    public LocalDateTime startPunkt(){
        return delegate(this);
    }

    public LocalDateTime endPunkt(){
        return delegate(this);
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Buchungszeitraum entity = (Buchungszeitraum) o;
        return Objects.equals(start, entity.start)  && Objects.equals(end, entity.end)  && Objects.equals(zimmernummer, entity.zimmernummer) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(start, end, zimmernummer);
    }
}