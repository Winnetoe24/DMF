package de.smart.city.cemetery;

import java.time.LocalDate;

/**
 * Delegate von Plot * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PlotDelegate {
    static {
        Plot.delegate = new PlotDelegate();
    }

}