package de.smart.city.snow_removal;

import java.time.LocalDateTime;

/**
 * Delegate von TreatmentOperation * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TreatmentOperationDelegate {
    static {
        TreatmentOperation.delegate = new TreatmentOperationDelegate();
    }

}