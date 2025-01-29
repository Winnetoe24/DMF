package de.smart.city.bathrooms;

/**
 **/
public enum CleaningStatus {
    CLEAN(),
    NEEDS_CLEANING(),
    IN_PROGRESS(),
    OUT_OF_SERVICE(),
    EMERGENCY();


    CleaningStatus(){
        
    }
}