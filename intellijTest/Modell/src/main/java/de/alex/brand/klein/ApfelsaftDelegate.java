package de.alex.brand.klein;

import java.time.LocalDate;

/**
 * Delegate von Apfelsaft * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ApfelsaftDelegate {
    static {
        Apfelsaft.delegate = new ApfelsaftDelegate();
    }

}