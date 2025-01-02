package de.beispiel.hotel;

/**
 * Delegate von Zimmer * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ZimmerDelegate implements IZimmerDelegate {
    @Override
    public boolean contains(Zimmer caller, java.time.LocalDateTime zeitpunkt){
        return false;
    }

    @Override
    public java.time.LocalDateTime startPunkt(Zimmer caller){
        return null;
    }

    @Override
    public java.time.LocalDateTime endPunkt(Zimmer caller){
        return null;
    }
}