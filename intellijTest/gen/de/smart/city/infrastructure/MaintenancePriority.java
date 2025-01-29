package de.smart.city.infrastructure;

/**
 **/
public enum MaintenancePriority {
    EMERGENCY(1, "Immediate action required"),
    HIGH(2, "Address within 24 hours"),
    MEDIUM(3, "Address within 1 week"),
    LOW(4, "Schedule during routine maintenance");

    protected int level;
    protected String description;

    MaintenancePriority(int level, String description){
        
        this.level = level;
        this.description = description;
    }
}