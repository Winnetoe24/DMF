package de.smart.city.fintech;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class FinancialInstitution extends Asset implements Auditable, Secureable {
    protected static FinancialInstitutionDelegate delegate;
    protected String institutionId;
    protected boolean isActive;

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public java.time.LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public String getInstitutionId() {
        return this.institutionId;
    }

    public void setInstitutionId(String institutionId) {
        this.institutionId = institutionId;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FinancialInstitution entity = (FinancialInstitution) o;
        return Objects.equals(institutionId, entity.institutionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(institutionId);
    }
}