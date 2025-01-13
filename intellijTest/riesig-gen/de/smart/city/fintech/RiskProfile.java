package de.smart.city.fintech;

import java.time.LocalDate;
import java.util.Objects;

/**
 **/
public class RiskProfile implements RiskAssessable {
    protected static RiskProfileDelegate delegate;
    protected int creditScore;
    protected double defaultProbability;
    /**
     * TODO []
     **/
    protected String riskIndicators;
    protected LocalDate lastAssessment;

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public int getRiskScore(){
        return delegate.getRiskScore(this);
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(){
        return delegate.getRiskFactors(this);
    }

    public boolean isHighRisk(){
        return delegate.isHighRisk(this);
    }

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    public int getCreditScore() {
        return this.creditScore;
    }

    public void setCreditScore(int creditScore) {
        this.creditScore = creditScore;
    }

    public double getDefaultProbability() {
        return this.defaultProbability;
    }

    public void setDefaultProbability(double defaultProbability) {
        this.defaultProbability = defaultProbability;
    }

    /**
     * TODO []
     **/
    public String getRiskIndicators() {
        return this.riskIndicators;
    }

    /**
     * TODO []
     **/
    public void setRiskIndicators(String riskIndicators) {
        this.riskIndicators = riskIndicators;
    }

    public LocalDate getLastAssessment() {
        return this.lastAssessment;
    }

    public void setLastAssessment(LocalDate lastAssessment) {
        this.lastAssessment = lastAssessment;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RiskProfile entity = (RiskProfile) o;
        return Objects.equals(creditScore, entity.creditScore)  && Objects.equals(riskIndicators, entity.riskIndicators)  && Objects.equals(lastAssessment, entity.lastAssessment)  && Objects.equals(defaultProbability, entity.defaultProbability) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(creditScore, riskIndicators, lastAssessment, defaultProbability);
    }
}