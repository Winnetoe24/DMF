package de.smart.city.fintech;

import java.time.LocalDate;
import java.util.Objects;

public class RiskAssessment implements RiskAssessable, Auditable {
    protected static RiskAssessmentDelegate delegate;
    protected String assessmentId;
    protected FinancialInstitution institution;
    protected RiskProfile profile;
    protected LocalDate assessmentDate;

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
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

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public boolean isHighRisk(){
        return delegate.isHighRisk(this);
    }

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public String getAssessmentId() {
        return this.assessmentId;
    }

    public void setAssessmentId(String assessmentId) {
        this.assessmentId = assessmentId;
    }

    public FinancialInstitution getInstitution() {
        return this.institution;
    }

    public void setInstitution(FinancialInstitution institution) {
        this.institution = institution;
    }

    public RiskProfile getProfile() {
        return this.profile;
    }

    public void setProfile(RiskProfile profile) {
        this.profile = profile;
    }

    public LocalDate getAssessmentDate() {
        return this.assessmentDate;
    }

    public void setAssessmentDate(LocalDate assessmentDate) {
        this.assessmentDate = assessmentDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RiskAssessment entity = (RiskAssessment) o;
        return Objects.equals(assessmentId, entity.assessmentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assessmentId);
    }
}