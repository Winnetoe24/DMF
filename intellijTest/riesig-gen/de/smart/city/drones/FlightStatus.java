package de.smart.city.drones;

/**
 **/
public enum FlightStatus {
    GROUNDED(),
    FLYING(),
    CHARGING(),
    MAINTENANCE(),
    EMERGENCY();


    FlightStatus(){
        
    }
}