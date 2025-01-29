package de.smart.city.fintech;

public interface RiskAssessable {
    public int getRiskScore();
    /**
     * TODO []
     **/
    public String getRiskFactors();
    public boolean isHighRisk();
    public void updateRiskProfile();
    /**
     * TODO []
     **/
    public String getMitigationStrategies();

}