package de.library.management.facilities;

/**
 * Delegate von Building * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BuildingDelegate {
    static {
        Building.delegate = new BuildingDelegate();
    }

}