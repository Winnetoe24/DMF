package de.smart.city.healthcare_extended;

import java.time.LocalDateTime;

/**
 * Delegate von Treatment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TreatmentDelegate {
    static {
        Treatment.delegate = new TreatmentDelegate();
    }

}