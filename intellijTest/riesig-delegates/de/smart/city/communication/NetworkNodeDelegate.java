package de.smart.city.communication;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von NetworkNode * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class NetworkNodeDelegate {
    static {
        NetworkNode.delegate = new NetworkNodeDelegate();
    }

}