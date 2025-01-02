package de.beispiel.hotel;

/**
 * Delegate von Zeitraum * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ZeitraumDelegate implements IZeitraumDelegate {
    @Override
    public boolean contains(Zeitraum caller, java.time.LocalDateTime zeitpunkt){
        return false;
    }

    @Override
    public java.time.LocalDateTime startPunkt(Zeitraum caller){
        return null;
    }

    @Override
    public java.time.LocalDateTime endPunkt(Zeitraum caller){
        return null;
    }
}