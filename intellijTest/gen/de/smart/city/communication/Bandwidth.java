package de.smart.city.communication;

/**
 **/
public enum Bandwidth {
    LOW(10),
    MEDIUM(100),
    HIGH(1000),
    ULTRA(10000);

    protected int speed;

    Bandwidth(int speed){
        
        this.speed = speed;
    }
}