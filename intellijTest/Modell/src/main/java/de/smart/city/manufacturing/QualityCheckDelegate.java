package de.smart.city.manufacturing;

import java.time.LocalDateTime;

/**
 * Delegate von QualityCheck * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class QualityCheckDelegate {
    static {
        QualityCheck.delegate = new QualityCheckDelegate();
    }

}