package de.smart.city.postal;

/**
 **/
public enum DeliveryStatus {
    RECEIVED(),
    SORTING(),
    IN_TRANSIT(),
    OUT_FOR_DELIVERY(),
    DELIVERED();


    DeliveryStatus(){
        
    }
}