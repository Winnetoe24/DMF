package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;

/**
 * Delegate von Reminder * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ReminderDelegate {
    static {
        Reminder.delegate = new ReminderDelegate();
    }

}