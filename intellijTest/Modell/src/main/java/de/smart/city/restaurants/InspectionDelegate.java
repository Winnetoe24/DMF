package de.smart.city.restaurants;

import java.time.LocalDate;

/**
 * Delegate von Inspection * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class InspectionDelegate {
    static {
        Inspection.delegate = new InspectionDelegate();
    }

}