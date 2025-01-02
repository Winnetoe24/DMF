package de.beispiel.hotel;

import java.time.LocalDateTime;

public interface IBuchungszeitraumDelegate {
    /**
     * Kommentar über Funktion
     **/
    public Zimmer getZimmer(Buchungszeitraum caller, Hotel hotel);
    public boolean contains(Buchungszeitraum caller, LocalDateTime zeitpunkt);
    public LocalDateTime startPunkt(Buchungszeitraum caller);
    public LocalDateTime endPunkt(Buchungszeitraum caller);

}