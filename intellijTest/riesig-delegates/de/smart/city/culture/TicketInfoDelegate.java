package de.smart.city.culture;

/**
 * Delegate von TicketInfo * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TicketInfoDelegate {
    static {
        TicketInfo.delegate = new TicketInfoDelegate();
    }
    public double calculateFinalPrice(TicketInfo caller){
        return 0d;
    }
}