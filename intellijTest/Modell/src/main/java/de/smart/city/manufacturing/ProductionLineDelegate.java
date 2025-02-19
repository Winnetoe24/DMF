package de.smart.city.manufacturing;

import java.time.LocalDateTime;

/**
 * Delegate von ProductionLine * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ProductionLineDelegate {
    static {
        ProductionLine.delegate = new ProductionLineDelegate();
    }

}