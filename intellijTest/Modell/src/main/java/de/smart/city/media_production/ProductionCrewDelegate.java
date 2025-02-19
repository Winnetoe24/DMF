package de.smart.city.media_production;

/**
 * Delegate von ProductionCrew * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ProductionCrewDelegate {
    static {
        ProductionCrew.delegate = new ProductionCrewDelegate();
    }

}