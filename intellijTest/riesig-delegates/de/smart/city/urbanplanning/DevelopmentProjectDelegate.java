package de.smart.city.urbanplanning;

import java.time.LocalDate;

/**
 * Delegate von DevelopmentProject * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DevelopmentProjectDelegate {
    static {
        DevelopmentProject.delegate = new DevelopmentProjectDelegate();
    }

}