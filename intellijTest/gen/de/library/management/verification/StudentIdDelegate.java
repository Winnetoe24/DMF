package de.library.management.verification;

import de.library.management.users.User;
import java.time.LocalDate;

/**
 * Delegate von StudentId * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class StudentIdDelegate {
    static {
        StudentId.delegate = new StudentIdDelegate();
    }

}