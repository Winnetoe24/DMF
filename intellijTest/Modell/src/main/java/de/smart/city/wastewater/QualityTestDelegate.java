package de.smart.city.wastewater;

import java.time.LocalDateTime;

/**
 * Delegate von QualityTest * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class QualityTestDelegate {
    static {
        QualityTest.delegate = new QualityTestDelegate();
    }

}