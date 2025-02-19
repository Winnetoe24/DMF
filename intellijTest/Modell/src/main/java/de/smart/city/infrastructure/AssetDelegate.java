package de.smart.city.infrastructure;

import java.time.LocalDate;

/**
 * Delegate von Asset * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AssetDelegate {
    static {
        Asset.delegate = new AssetDelegate();
    }

}