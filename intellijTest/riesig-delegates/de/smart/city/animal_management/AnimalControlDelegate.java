package de.smart.city.animal_management;

import java.time.LocalDateTime;

/**
 * Delegate von AnimalControl * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AnimalControlDelegate {
    static {
        AnimalControl.delegate = new AnimalControlDelegate();
    }

}