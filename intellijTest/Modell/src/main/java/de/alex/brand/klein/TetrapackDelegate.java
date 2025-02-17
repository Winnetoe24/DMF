package de.alex.brand.klein;

import java.time.LocalDate;

/**
 * Delegate von Tetrapack * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TetrapackDelegate {
    static {
        Tetrapack.delegate = new TetrapackDelegate();
    }
    public void tata(Tetrapack caller, int i, Tetrapack t, long sad){
        ;
    }
}