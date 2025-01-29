package de.smart.city.lighting;

/**
 **/
public enum BrightnessLevel {
    OFF(0),
    DIM(25),
    MEDIUM(50),
    BRIGHT(100);

    protected int percentage;

    BrightnessLevel(int percentage){
        
        this.percentage = percentage;
    }
}