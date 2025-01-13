package de.smart.city.fintech;

/**
 * Delegate von FraudDetection * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FraudDetectionDelegate {
    static {
        FraudDetection.delegate = new FraudDetectionDelegate();
    }
    public void updateRiskProfile(FraudDetection caller){
        ;
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(FraudDetection caller){
        return "";
    }

    public boolean decrypt(FraudDetection caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(FraudDetection caller){
        return "";
    }

    public void revokeAccess(FraudDetection caller, String userId){
        ;
    }

    public boolean encrypt(FraudDetection caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(FraudDetection caller){
        return "";
    }

    public int getRiskScore(FraudDetection caller){
        return 0;
    }

    public boolean isHighRisk(FraudDetection caller){
        return false;
    }

    public boolean hasPermission(FraudDetection caller, String role){
        return false;
    }
}