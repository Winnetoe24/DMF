package de.smart.city.fintech;
import java.util.Objects;

public class FraudDetection implements RiskAssessable, Secureable {
    protected static FraudDetectionDelegate delegate;
    protected String detectionId;
    protected Transaction transaction;
    protected RiskProfile risk;
    protected boolean requiresReview;
    protected String resolution;

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public int getRiskScore(){
        return delegate.getRiskScore(this);
    }

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
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
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    public String getDetectionId() {
        return this.detectionId;
    }

    public void setDetectionId(String detectionId) {
        this.detectionId = detectionId;
    }

    public Transaction getTransaction() {
        return this.transaction;
    }

    public void setTransaction(Transaction transaction) {
        this.transaction = transaction;
    }

    public RiskProfile getRisk() {
        return this.risk;
    }

    public void setRisk(RiskProfile risk) {
        this.risk = risk;
    }

    public boolean getRequiresReview() {
        return this.requiresReview;
    }

    public void setRequiresReview(boolean requiresReview) {
        this.requiresReview = requiresReview;
    }

    public String getResolution() {
        return this.resolution;
    }

    public void setResolution(String resolution) {
        this.resolution = resolution;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FraudDetection entity = (FraudDetection) o;
        return Objects.equals(detectionId, entity.detectionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(detectionId);
    }
}