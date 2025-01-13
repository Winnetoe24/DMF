package de.smart.city.smartgrid;

import java.time.LocalDateTime;

/**
 * Delegate von PowerFlow * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class PowerFlowDelegate {
    static {
        PowerFlow.delegate = new PowerFlowDelegate();
    }

}