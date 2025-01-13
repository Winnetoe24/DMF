package de.smart.city.manufacturing;

import java.time.LocalDate;

/**
 * Delegate von Machine * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MachineDelegate {
    static {
        Machine.delegate = new MachineDelegate();
    }

}