package de.smart.city.fintech;

import java.time.LocalDate;
import java.util.Objects;

public class FinancialAccount implements Transactional, Auditable, Secureable {
    protected static FinancialAccountDelegate delegate;
    protected String accountId;
    protected FinancialInstitution institution;
    protected String accountType;
    protected double balance;
    protected String currency;
    protected boolean isFrozen;
    protected LocalDate openedDate;

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public boolean verifySignature(String signature){
        return delegate.verifySignature(this, signature);
    }

    public void logTransaction(){
        delegate.logTransaction(this);
    }

    public boolean validate(){
        return delegate.validate(this);
    }

    public String generateHash(){
        return delegate.generateHash(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    public double calculateFees(){
        return delegate.calculateFees(this);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
    }

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public String getAccountId() {
        return this.accountId;
    }

    public void setAccountId(String accountId) {
        this.accountId = accountId;
    }

    public FinancialInstitution getInstitution() {
        return this.institution;
    }

    public void setInstitution(FinancialInstitution institution) {
        this.institution = institution;
    }

    public String getAccountType() {
        return this.accountType;
    }

    public void setAccountType(String accountType) {
        this.accountType = accountType;
    }

    public double getBalance() {
        return this.balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getCurrency() {
        return this.currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }

    public boolean getIsFrozen() {
        return this.isFrozen;
    }

    public void setIsFrozen(boolean isFrozen) {
        this.isFrozen = isFrozen;
    }

    public LocalDate getOpenedDate() {
        return this.openedDate;
    }

    public void setOpenedDate(LocalDate openedDate) {
        this.openedDate = openedDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FinancialAccount entity = (FinancialAccount) o;
        return Objects.equals(accountId, entity.accountId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(accountId);
    }
}