package de.smart.city.climate;

import java.time.LocalDate;

/**
 * Delegate von ClimateProject * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ClimateProjectDelegate {
    static {
        ClimateProject.delegate = new ClimateProjectDelegate();
    }

}