package de.smart.city.infrastructure;

/**
 * Delegate von GeoLocation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class GeoLocationDelegate {
    static {
        GeoLocation.delegate = new GeoLocationDelegate();
    }
    public double calculateDistance(GeoLocation caller, GeoLocation other){
        return 0d;
    }
}