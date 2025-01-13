package de.smart.city.fintech;
import java.util.Objects;

public class Transaction implements Transactional, Auditable, RiskAssessable {
    protected static TransactionDelegate delegate;
    protected String transactionId;
    protected TransactionType type;
    protected TransactionMetadata metadata;
    protected FinancialAccount source;
    protected FinancialAccount destination;
    protected boolean isProcessed;
    protected String status;

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public int getRiskScore(){
        return delegate.getRiskScore(this);
    }

    public void updateRiskProfile(){
        delegate.updateRiskProfile(this);
    }

    public boolean validate(){
        return delegate.validate(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
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

    public boolean verifySignature(String signature){
        return delegate.verifySignature(this, signature);
    }

    public void logTransaction(){
        delegate.logTransaction(this);
    }

    public double calculateFees(){
        return delegate.calculateFees(this);
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public String generateHash(){
        return delegate.generateHash(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    /**
     * TODO []
     **/
    public String getMitigationStrategies(){
        return delegate.getMitigationStrategies(this);
    }

    public String getTransactionId() {
        return this.transactionId;
    }

    public void setTransactionId(String transactionId) {
        this.transactionId = transactionId;
    }

    public TransactionType getType() {
        return this.type;
    }

    public void setType(TransactionType type) {
        this.type = type;
    }

    public TransactionMetadata getMetadata() {
        return this.metadata;
    }

    public void setMetadata(TransactionMetadata metadata) {
        this.metadata = metadata;
    }

    public FinancialAccount getSource() {
        return this.source;
    }

    public void setSource(FinancialAccount source) {
        this.source = source;
    }

    public FinancialAccount getDestination() {
        return this.destination;
    }

    public void setDestination(FinancialAccount destination) {
        this.destination = destination;
    }

    public boolean getIsProcessed() {
        return this.isProcessed;
    }

    public void setIsProcessed(boolean isProcessed) {
        this.isProcessed = isProcessed;
    }

    public String getStatus() {
        return this.status;
    }

    public void setStatus(String status) {
        this.status = status;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Transaction entity = (Transaction) o;
        return Objects.equals(transactionId, entity.transactionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(transactionId);
    }
}