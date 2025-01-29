package de.smart.city.fintech;

import java.time.LocalDateTime;
import java.util.Objects;

public class SecurityIncident implements Auditable, RiskAssessable {
    protected static SecurityIncidentDelegate delegate;
    protected String incidentId;
    protected SecurityLevel impactLevel;
    protected LocalDateTime detectionTime;
    protected String description;
    protected boolean resolved;

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public int getRiskScore(){
        return delegate.getRiskScore(this);
    }

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public boolean isHighRisk(){
        return delegate.isHighRisk(this);
    }

    /**
     * TODO []
     **/
    public String getRiskFactors(){
        return delegate.getRiskFactors(this);
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public String getIncidentId() {
        return this.incidentId;
    }

    public void setIncidentId(String incidentId) {
        this.incidentId = incidentId;
    }

    public SecurityLevel getImpactLevel() {
        return this.impactLevel;
    }

    public void setImpactLevel(SecurityLevel impactLevel) {
        this.impactLevel = impactLevel;
    }

    public LocalDateTime getDetectionTime() {
        return this.detectionTime;
    }

    public void setDetectionTime(LocalDateTime detectionTime) {
        this.detectionTime = detectionTime;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public boolean getResolved() {
        return this.resolved;
    }

    public void setResolved(boolean resolved) {
        this.resolved = resolved;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SecurityIncident entity = (SecurityIncident) o;
        return Objects.equals(incidentId, entity.incidentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(incidentId);
    }
}