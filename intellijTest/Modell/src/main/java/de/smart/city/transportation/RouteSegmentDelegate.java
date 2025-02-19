package de.smart.city.transportation;

import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von RouteSegment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RouteSegmentDelegate {
    static {
        RouteSegment.delegate = new RouteSegmentDelegate();
    }
    public double calculateCongestion(RouteSegment caller){
        return 0d;
    }
}