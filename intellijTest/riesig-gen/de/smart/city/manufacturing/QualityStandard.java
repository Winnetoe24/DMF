package de.smart.city.manufacturing;

/**
 **/
public enum QualityStandard {
    ISO_NINE_THOUSAND_ONE("ISO-9001", 1),
    ISO_FOURTEEN_THOUSAND_ONE("ISO-14001", 1),
    GMP("GMP", 2),
    HACCP("HACCP", 2),
    SIX_SIGMA("6σ", 3);

    protected String code;
    protected int level;

    QualityStandard(String code, int level){
        
        this.code = code;
        this.level = level;
    }
}