package de.smart.city.transportation;

/**
 * Delegate von TransportRoute * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TransportRouteDelegate {
    static {
        TransportRoute.delegate = new TransportRouteDelegate();
    }

}