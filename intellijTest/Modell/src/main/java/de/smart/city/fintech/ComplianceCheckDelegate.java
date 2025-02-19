package de.smart.city.fintech;

/**
 * Delegate von ComplianceCheck * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ComplianceCheckDelegate {
    static {
        ComplianceCheck.delegate = new ComplianceCheckDelegate();
    }
    public int getRiskScore(ComplianceCheck caller){
        return 0;
    }

    public boolean isHighRisk(ComplianceCheck caller){
        return false;
    }

    public boolean isCompliant(ComplianceCheck caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(ComplianceCheck caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(ComplianceCheck caller){
        return "";
    }

    public String getAuditor(ComplianceCheck caller){
        return "";
    }

    public void addAuditEntry(ComplianceCheck caller, String entry){
        ;
    }

    public java.time.LocalDate getLastAuditDate(ComplianceCheck caller){
        return null;
    }

    public void updateRiskProfile(ComplianceCheck caller){
        ;
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(ComplianceCheck caller){
        return "";
    }
}