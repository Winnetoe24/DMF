package de.smart.city.wastewater;

/**
 **/
public enum WaterQualityMetric {
    BOD("mg/L"),
    COD("mg/L"),
    TSS("mg/L"),
    PH("pH");

    protected String unit;

    WaterQualityMetric(String unit){
        
        this.unit = unit;
    }
}