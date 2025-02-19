package de.smart.city.communication;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von NetworkNode * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class NetworkNodeDelegate {
    static {
        NetworkNode.delegate = new NetworkNodeDelegate();
    }

}