package de.smart.city.animal_management;

import java.time.LocalDate;

/**
 * Delegate von Pet * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PetDelegate {
    static {
        Pet.delegate = new PetDelegate();
    }

}