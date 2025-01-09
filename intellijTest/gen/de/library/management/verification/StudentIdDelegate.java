package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.users.User;

/**
 * Delegate von StudentId * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class StudentIdDelegate {
    static {
        StudentId.delegate = new StudentIdDelegate();
    }

}