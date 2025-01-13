package de.smart.city.noise;

import java.time.LocalDateTime;

/**
 * Delegate von NoiseComplaint * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class NoiseComplaintDelegate {
    static {
        NoiseComplaint.delegate = new NoiseComplaintDelegate();
    }

}