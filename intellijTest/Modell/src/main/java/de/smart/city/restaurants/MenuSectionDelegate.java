package de.smart.city.restaurants;

/**
 * Delegate von MenuSection * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MenuSectionDelegate {
    static {
        MenuSection.delegate = new MenuSectionDelegate();
    }
    public double getAveragePrice(MenuSection caller){
        return 0d;
    }
}