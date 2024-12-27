package de.library.management.finance;

/**
 * Steuersätze
 **/
public enum TaxRate {
    STANDARD(19d),
    REDUCED(7d),
    ZERO(0d);

    protected double rate;

    TaxRate(double rate){
        
        this.rate = rate;
    }
}