package de.smart.city.transit_payment;

/**
 **/
public enum FareType {
    SINGLE(2.5d),
    DAY_PASS(8d),
    WEEK_PASS(30d),
    MONTH_PASS(100d);

    protected double baseRate;

    FareType(double baseRate){
        
        this.baseRate = baseRate;
    }
}