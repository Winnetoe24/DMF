package de.smart.city.fintech;

import java.time.LocalDate;

/**
 * Delegate von RiskAssessment * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RiskAssessmentDelegate {
    static {
        RiskAssessment.delegate = new RiskAssessmentDelegate();
    }
    /**
     * TODO []
     **/
    public String getMitigationStrategies(RiskAssessment caller){
        return "";
    }

    public int getRiskScore(RiskAssessment caller){
        return 0;
    }

    public boolean isCompliant(RiskAssessment caller){
        return false;
    }

    public String getAuditor(RiskAssessment caller){
        return "";
    }

    public boolean isHighRisk(RiskAssessment caller){
        return false;
    }

    public void addAuditEntry(RiskAssessment caller, String entry){
        ;
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(RiskAssessment caller){
        return "";
    }

    public LocalDate getLastAuditDate(RiskAssessment caller){
        return null;
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(RiskAssessment caller){
        return "";
    }

    public void updateRiskProfile(RiskAssessment caller){
        ;
    }
}