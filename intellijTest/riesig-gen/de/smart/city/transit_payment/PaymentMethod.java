package de.smart.city.transit_payment;

/**
 **/
public enum PaymentMethod {
    CARD(),
    MOBILE(),
    TOKEN(),
    CASH(),
    SUBSCRIPTION();


    PaymentMethod(){
        
    }
}