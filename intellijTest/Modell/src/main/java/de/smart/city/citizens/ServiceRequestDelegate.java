package de.smart.city.citizens;

import java.time.LocalDateTime;

/**
 * Delegate von ServiceRequest * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ServiceRequestDelegate {
    static {
        ServiceRequest.delegate = new ServiceRequestDelegate();
    }

}