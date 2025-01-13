package de.smart.city.communication;

import java.time.LocalDateTime;

/**
 * Delegate von DataTransfer * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class DataTransferDelegate {
    static {
        DataTransfer.delegate = new DataTransferDelegate();
    }

}