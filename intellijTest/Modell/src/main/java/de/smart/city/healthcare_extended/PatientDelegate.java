package de.smart.city.healthcare_extended;

import java.time.LocalDate;

/**
 * Delegate von Patient * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PatientDelegate {
    static {
        Patient.delegate = new PatientDelegate();
    }

}