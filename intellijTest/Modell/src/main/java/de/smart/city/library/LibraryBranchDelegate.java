package de.smart.city.library;

import de.smart.city.infrastructure.AssetStatus;
import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von LibraryBranch * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LibraryBranchDelegate {
    static {
        LibraryBranch.delegate = new LibraryBranchDelegate();
    }

}