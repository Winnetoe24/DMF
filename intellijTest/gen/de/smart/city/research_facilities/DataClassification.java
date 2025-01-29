package de.smart.city.research_facilities;

/**
 **/
public enum DataClassification {
    PUBLIC(0, "1Y"),
    CONFIDENTIAL(1, "5Y"),
    RESTRICTED(2, "10Y"),
    CLASSIFIED(3, "25Y"),
    TOP_SECRET(4, "50Y");

    protected int securityLevel;
    protected String retentionPeriod;

    DataClassification(int securityLevel, String retentionPeriod){
        
        this.securityLevel = securityLevel;
        this.retentionPeriod = retentionPeriod;
    }
}