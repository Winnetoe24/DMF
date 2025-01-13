package de.smart.city.fintech;

import java.time.LocalDateTime;
import java.util.Objects;

public class AuditLog implements Auditable {
    protected static AuditLogDelegate delegate;
    protected String logId;
    protected Transaction transaction;
    protected LocalDateTime timestamp;
    protected String action;
    protected String performedBy;
    protected String details;

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public String getLogId() {
        return this.logId;
    }

    public void setLogId(String logId) {
        this.logId = logId;
    }

    public Transaction getTransaction() {
        return this.transaction;
    }

    public void setTransaction(Transaction transaction) {
        this.transaction = transaction;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public String getAction() {
        return this.action;
    }

    public void setAction(String action) {
        this.action = action;
    }

    public String getPerformedBy() {
        return this.performedBy;
    }

    public void setPerformedBy(String performedBy) {
        this.performedBy = performedBy;
    }
    public String getDetails() {
        return this.details;
    }

    public void setDetails(String details) {
        this.details = details;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AuditLog entity = (AuditLog) o;
        return Objects.equals(logId, entity.logId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(logId);
    }
}