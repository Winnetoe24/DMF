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

    public boolean contains(LocalDateTime zeitpunkt){
        return delegate.contains(this, zeitpunkt);
    }

    /**
     * Kommentar über Funktion
     **/
    public Zimmer getZimmer(Hotel hotel){
        return delegate.getZimmer(this, hotel);
    }

    public LocalDateTime startPunkt(){
        return delegate.startPunkt(this);
    }

    public LocalDateTime endPunkt(){
        return delegate.endPunkt(this);
    }
    /**
     * Kommentar über einem Argument
     **/
    public LocalDateTime getStart() {
        return this.start;
    }
    /**
     * Kommentar über einem Argument
     **/
    public void setStart(LocalDateTime start) {
        this.start = start;
    }
    public LocalDateTime getEnd() {
        return this.end;
    }
    public void setEnd(LocalDateTime end) {
        this.end = end;
    }
    public long getZimmernummer() {
        return this.zimmernummer;
    }
    public void setZimmernummer(long zimmernummer) {
        this.zimmernummer = zimmernummer;
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