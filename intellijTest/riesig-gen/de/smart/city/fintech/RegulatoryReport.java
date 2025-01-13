package de.smart.city.fintech;

import java.time.LocalDate;
import java.util.Objects;

public class RegulatoryReport implements Auditable, Secureable {
    protected static RegulatoryReportDelegate delegate;
    protected String reportId;
    protected FinancialInstitution institution;
    protected String reportType;
    protected LocalDate reportingPeriod;
    protected boolean submitted;

    /**
     * TODO []
     **/
    public String getAuditTrail(){
        return delegate.getAuditTrail(this);
    }

    public boolean isCompliant(){
        return delegate.isCompliant(this);
    }

    public String getAuditor(){
        return delegate.getAuditor(this);
    }

    public void addAuditEntry(String entry){
        delegate.addAuditEntry(this, entry);
    }

    public LocalDate getLastAuditDate(){
        return delegate.getLastAuditDate(this);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    public String getReportId() {
        return this.reportId;
    }

    public void setReportId(String reportId) {
        this.reportId = reportId;
    }

    public FinancialInstitution getInstitution() {
        return this.institution;
    }

    public void setInstitution(FinancialInstitution institution) {
        this.institution = institution;
    }

    public String getReportType() {
        return this.reportType;
    }

    public void setReportType(String reportType) {
        this.reportType = reportType;
    }

    public LocalDate getReportingPeriod() {
        return this.reportingPeriod;
    }

    public void setReportingPeriod(LocalDate reportingPeriod) {
        this.reportingPeriod = reportingPeriod;
    }

    public boolean getSubmitted() {
        return this.submitted;
    }

    public void setSubmitted(boolean submitted) {
        this.submitted = submitted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RegulatoryReport entity = (RegulatoryReport) o;
        return Objects.equals(reportId, entity.reportId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(reportId);
    }
}