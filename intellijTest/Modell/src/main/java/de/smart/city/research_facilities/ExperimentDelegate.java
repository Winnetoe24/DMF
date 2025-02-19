package de.smart.city.research_facilities;

import java.time.LocalDateTime;

/**
 * Delegate von Experiment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ExperimentDelegate {
    static {
        Experiment.delegate = new ExperimentDelegate();
    }

}