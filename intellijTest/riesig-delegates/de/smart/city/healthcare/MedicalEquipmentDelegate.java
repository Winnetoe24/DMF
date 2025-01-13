package de.smart.city.healthcare;

import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;

/**
 * Delegate von MedicalEquipment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MedicalEquipmentDelegate {
    static {
        MedicalEquipment.delegate = new MedicalEquipmentDelegate();
    }

}