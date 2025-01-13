package de.smart.city.research_facilities;

import java.time.LocalDate;
import java.util.Objects;

public class ComplianceAudit {
    protected static ComplianceAuditDelegate delegate;
    protected String auditId;
    protected Laboratory lab;
    protected LocalDate auditDate;
    protected String auditor;
    protected boolean passed;



    public String getAuditId() {
        return this.auditId;
    }

    public void setAuditId(String auditId) {
        this.auditId = auditId;
    }

    public Laboratory getLab() {
        return this.lab;
    }

    public void setLab(Laboratory lab) {
        this.lab = lab;
    }

    public LocalDate getAuditDate() {
        return this.auditDate;
    }

    public void setAuditDate(LocalDate auditDate) {
        this.auditDate = auditDate;
    }

    public String getAuditor() {
        return this.auditor;
    }

    public void setAuditor(String auditor) {
        this.auditor = auditor;
    }

    public boolean getPassed() {
        return this.passed;
    }

    public void setPassed(boolean passed) {
        this.passed = passed;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ComplianceAudit entity = (ComplianceAudit) o;
        return Objects.equals(auditId, entity.auditId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(auditId);
    }
}