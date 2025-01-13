package de.smart.city.buildings;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von Building * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BuildingDelegate {
    static {
        Building.delegate = new BuildingDelegate();
    }

}