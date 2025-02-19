package de.smart.city.animal_management;

import java.time.LocalDate;

/**
 * Delegate von PetLicense * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PetLicenseDelegate {
    static {
        PetLicense.delegate = new PetLicenseDelegate();
    }

}