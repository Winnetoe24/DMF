package de.library.management.lending;

import de.library.management.media.MediaItem;
import java.time.LocalDate;
import de.library.management.users.User;

/**
 * Delegate von LendingProcess * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LendingProcessDelegate {
    static {
        LendingProcess.delegate = new LendingProcessDelegate();
    }

}