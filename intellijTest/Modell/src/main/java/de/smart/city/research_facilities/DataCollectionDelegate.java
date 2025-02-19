package de.smart.city.research_facilities;

import java.time.LocalDateTime;

/**
 * Delegate von DataCollection * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DataCollectionDelegate {
    static {
        DataCollection.delegate = new DataCollectionDelegate();
    }

}