package de.smart.city.fintech;

import java.time.LocalDate;

/**
 * Delegate von RiskProfile * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RiskProfileDelegate {
    static {
        RiskProfile.delegate = new RiskProfileDelegate();
    }
    public int getRiskScore(RiskProfile caller){
        return 0;
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(RiskProfile caller){
        return "";
    }

    public boolean isHighRisk(RiskProfile caller){
        return false;
    }

    public void updateRiskProfile(RiskProfile caller){
        ;
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(RiskProfile caller){
        return "";
    }
}