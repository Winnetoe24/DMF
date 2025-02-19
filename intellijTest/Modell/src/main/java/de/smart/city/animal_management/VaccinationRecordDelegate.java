package de.smart.city.animal_management;

import java.time.LocalDate;

/**
 * Delegate von VaccinationRecord * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VaccinationRecordDelegate {
    static {
        VaccinationRecord.delegate = new VaccinationRecordDelegate();
    }
    public boolean isValid(VaccinationRecord caller){
        return false;
    }
}