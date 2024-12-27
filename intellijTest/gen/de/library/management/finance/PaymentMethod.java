package de.library.management.finance;

/**
 * Zahlungsarten
 **/
public enum PaymentMethod {
    CASH(),
    CREDIT_CARD(),
    DEBIT_CARD(),
    BANK_TRANSFER(),
    PAYPAL();


    PaymentMethod(){
        
    }
}