package de.smart.city.smartgrid;

import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDate;

/**
 * Delegate von GridNode * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class GridNodeDelegate {
    static {
        GridNode.delegate = new GridNodeDelegate();
    }

}