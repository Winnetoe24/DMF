package de.library.management.employees;

import java.time.LocalDate;
import de.library.management.facilities.Building;

/**
 * Delegate von Employee * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class EmployeeDelegate {
    static {
        Employee.delegate = new EmployeeDelegate();
    }

}