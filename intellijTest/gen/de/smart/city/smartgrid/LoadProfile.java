package de.smart.city.smartgrid;

/**
 **/
public enum LoadProfile {
    RESIDENTIAL(5d),
    COMMERCIAL(20d),
    INDUSTRIAL(100d),
    MUNICIPAL(50d);

    protected double baseLoad;

    LoadProfile(double baseLoad){
        
        this.baseLoad = baseLoad;
    }
}