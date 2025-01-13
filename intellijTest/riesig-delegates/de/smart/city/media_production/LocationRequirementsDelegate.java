package de.smart.city.media_production;

/**
 * Delegate von LocationRequirements * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LocationRequirementsDelegate {
    static {
        LocationRequirements.delegate = new LocationRequirementsDelegate();
    }
    public boolean checkCompliance(LocationRequirements caller){
        return false;
    }
}