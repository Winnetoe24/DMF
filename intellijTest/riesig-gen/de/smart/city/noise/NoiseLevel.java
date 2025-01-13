package de.smart.city.noise;

/**
 **/
public enum NoiseLevel {
    LOW(40),
    MODERATE(60),
    HIGH(80),
    DANGEROUS(100);

    protected int decibels;

    NoiseLevel(int decibels){
        
        this.decibels = decibels;
    }
}