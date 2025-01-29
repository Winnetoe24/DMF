package de.smart.city.fintech;
import java.util.Objects;

public class ComplianceCheck implements Auditable, RiskAssessable {
    protected static ComplianceCheckDelegate delegate;
    protected String checkId;
    protected Transaction transaction;
    protected boolean passedKYC;
    protected boolean passedAML;

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public int getRiskScore(){
        return delegate.getRiskScore(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
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

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public String getCheckId() {
        return this.checkId;
    }

    public void setCheckId(String checkId) {
        this.checkId = checkId;
    }

    public Transaction getTransaction() {
        return this.transaction;
    }

    public void setTransaction(Transaction transaction) {
        this.transaction = transaction;
    }

    public boolean getPassedKYC() {
        return this.passedKYC;
    }

    public void setPassedKYC(boolean passedKYC) {
        this.passedKYC = passedKYC;
    }

    public boolean getPassedAML() {
        return this.passedAML;
    }

    public void setPassedAML(boolean passedAML) {
        this.passedAML = passedAML;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ComplianceCheck entity = (ComplianceCheck) o;
        return Objects.equals(checkId, entity.checkId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(checkId);
    }
}