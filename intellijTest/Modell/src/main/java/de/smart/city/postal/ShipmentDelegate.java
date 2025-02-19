package de.smart.city.postal;

import java.time.LocalDateTime;

/**
 * Delegate von Shipment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ShipmentDelegate {
    static {
        Shipment.delegate = new ShipmentDelegate();
    }

}