package de.smart.city.climate;

import java.time.LocalDate;

/**
 * Delegate von EmissionReport * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EmissionReportDelegate {
    static {
        EmissionReport.delegate = new EmissionReportDelegate();
    }

}