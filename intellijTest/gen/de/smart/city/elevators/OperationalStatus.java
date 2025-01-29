package de.smart.city.elevators;

/**
 **/
public enum OperationalStatus {
    OPERATIONAL(),
    MAINTENANCE(),
    OUT_OF_SERVICE(),
    INSPECTION(),
    EMERGENCY();


    OperationalStatus(){
        
    }
}