package de.smart.city.healthcare;

import java.time.LocalDateTime;

/**
 * Delegate von PatientHistory * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PatientHistoryDelegate {
    static {
        PatientHistory.delegate = new PatientHistoryDelegate();
    }
    public boolean isUrgent(PatientHistory caller){
        return false;
    }
}