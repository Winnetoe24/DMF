package de.beispiel.hotel;

/**
 * Delegate von Zimmer * Wird nur initial generiert. * Methoden müssen implementiert werden. **/
public class ZimmerDelegate {
    public boolean contains(Zimmer caller, java.time.LocalDateTime zeitpunkt){
        return false;
    }

    public java.time.LocalDateTime startPunkt(Zimmer caller){
        return null;
    }

    public java.time.LocalDateTime endPunkt(Zimmer caller){
        return null;
    }
}