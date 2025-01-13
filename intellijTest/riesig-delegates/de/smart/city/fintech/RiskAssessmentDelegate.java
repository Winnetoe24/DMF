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
    public void updateRiskProfile(RiskAssessment caller){
        ;
    }

    public void addAuditEntry(RiskAssessment caller, String entry){
        ;
    }

    public boolean isCompliant(RiskAssessment caller){
        return false;
    }

    public boolean isHighRisk(RiskAssessment caller){
        return false;
    }

    public int getRiskScore(RiskAssessment caller){
        return 0;
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(RiskAssessment caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(RiskAssessment caller){
        return "";
    }

    public String getAuditor(RiskAssessment caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(RiskAssessment caller){
        return "";
    }

    public LocalDate getLastAuditDate(RiskAssessment caller){
        return null;
    }
}