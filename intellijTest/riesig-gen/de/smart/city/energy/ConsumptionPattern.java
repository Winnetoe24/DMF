package de.smart.city.energy;

/**
 **/
public enum ConsumptionPattern {
    RESIDENTIAL("Home usage", 10d),
    COMMERCIAL("Business usage", 50d),
    INDUSTRIAL("Factory usage", 200d),
    PUBLIC("Municipal usage", 30d);

    protected String pattern;
    protected double baselineKwh;

    ConsumptionPattern(String pattern, double baselineKwh){
        
        this.pattern = pattern;
        this.baselineKwh = baselineKwh;
    }
}