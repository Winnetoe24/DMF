package de.smart.city.fintech;

import java.time.LocalDate;

/**
 * Delegate von RegulatoryReport * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class RegulatoryReportDelegate {
    static {
        RegulatoryReport.delegate = new RegulatoryReportDelegate();
    }
    public boolean decrypt(RegulatoryReport caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(RegulatoryReport caller){
        return "";
    }

    public void addAuditEntry(RegulatoryReport caller, String entry){
        ;
    }

    public boolean isCompliant(RegulatoryReport caller){
        return false;
    }

    public LocalDate getLastAuditDate(RegulatoryReport caller){
        return null;
    }

    public boolean hasPermission(RegulatoryReport caller, String role){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(RegulatoryReport caller){
        return "";
    }

    public void revokeAccess(RegulatoryReport caller, String userId){
        ;
    }

    public String getAuditor(RegulatoryReport caller){
        return "";
    }

    public boolean encrypt(RegulatoryReport caller){
        return false;
    }
}