package de.smart.city.research_facilities;

import java.time.LocalDateTime;

/**
 * Delegate von EquipmentSpecification * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EquipmentSpecificationDelegate {
    static {
        EquipmentSpecification.delegate = new EquipmentSpecificationDelegate();
    }
    public boolean meetsStandards(EquipmentSpecification caller){
        return false;
    }

    public boolean needsCalibration(EquipmentSpecification caller){
        return false;
    }
}