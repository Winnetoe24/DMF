package de.smart.city.parking;

import java.time.LocalDateTime;

/**
 * Delegate von ParkingTransaction * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ParkingTransactionDelegate {
    static {
        ParkingTransaction.delegate = new ParkingTransactionDelegate();
    }

}