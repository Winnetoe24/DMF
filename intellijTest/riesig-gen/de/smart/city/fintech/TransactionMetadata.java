package de.smart.city.fintech;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 * Complex financial data structures
 **/
public class TransactionMetadata implements Auditable, Secureable {
    protected static TransactionMetadataDelegate delegate;
    protected LocalDateTime timestamp;
    protected String originatorId;
    protected String beneficiaryId;
    protected double amount;
    protected String currency;
    protected String purpose;

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public boolean validate(){
        return delegate.validate(this);
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public String getOriginatorId() {
        return this.originatorId;
    }

    public void setOriginatorId(String originatorId) {
        this.originatorId = originatorId;
    }

    public String getBeneficiaryId() {
        return this.beneficiaryId;
    }

    public void setBeneficiaryId(String beneficiaryId) {
        this.beneficiaryId = beneficiaryId;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getCurrency() {
        return this.currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }

    public String getPurpose() {
        return this.purpose;
    }

    public void setPurpose(String purpose) {
        this.purpose = purpose;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TransactionMetadata entity = (TransactionMetadata) o;
        return Objects.equals(currency, entity.currency)  && Objects.equals(amount, entity.amount)  && Objects.equals(timestamp, entity.timestamp)  && Objects.equals(beneficiaryId, entity.beneficiaryId)  && Objects.equals(purpose, entity.purpose)  && Objects.equals(originatorId, entity.originatorId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(currency, amount, timestamp, beneficiaryId, purpose, originatorId);
    }
}