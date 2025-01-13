package de.smart.city.buildings;

/**
 **/
public enum SecurityLevel {
    HIGH(1),
    MEDIUM(2),
    LOW(3),
    PUBLIC(4);

    protected int clearance;

    SecurityLevel(int clearance){
        
        this.clearance = clearance;
    }
}