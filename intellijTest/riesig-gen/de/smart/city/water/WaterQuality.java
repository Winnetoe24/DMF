package de.smart.city.water;

/**
 **/
public enum WaterQuality {
    EXCELLENT(1, "Exceeds standards"),
    GOOD(2, "Meets standards"),
    FAIR(3, "Requires monitoring"),
    POOR(4, "Requires action"),
    CRITICAL(5, "Immediate action needed");

    protected int level;
    protected String description;

    WaterQuality(int level, String description){
        
        this.level = level;
        this.description = description;
    }
}