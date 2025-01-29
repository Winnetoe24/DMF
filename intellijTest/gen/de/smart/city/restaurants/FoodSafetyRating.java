package de.smart.city.restaurants;

/**
 **/
public enum FoodSafetyRating {
    A("Excellent"),
    B("Good"),
    C("Fair"),
    D("Poor"),
    F("Failed");

    protected String description;

    FoodSafetyRating(String description){
        
        this.description = description;
    }
}