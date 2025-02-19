package de.smart.city.healthcare;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von MedicalEquipment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MedicalEquipmentDelegate {
    static {
        MedicalEquipment.delegate = new MedicalEquipmentDelegate();
    }

}