package de.smart.city.snow_removal;

import java.time.LocalDateTime;

/**
 * Delegate von SnowRoute * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class SnowRouteDelegate {
    static {
        SnowRoute.delegate = new SnowRouteDelegate();
    }

}