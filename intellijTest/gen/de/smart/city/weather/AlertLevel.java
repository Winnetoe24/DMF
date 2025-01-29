package de.smart.city.weather;

/**
 **/
public enum AlertLevel {
    SEVERE("Immediate action required"),
    WARNING("Be prepared"),
    WATCH("Be aware"),
    ADVISORY("For information");

    protected String description;

    AlertLevel(String description){
        
        this.description = description;
    }
}