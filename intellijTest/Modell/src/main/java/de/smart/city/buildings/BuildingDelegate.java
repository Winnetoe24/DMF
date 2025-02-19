package de.smart.city.buildings;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von Building * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BuildingDelegate {
    static {
        Building.delegate = new BuildingDelegate();
    }

}