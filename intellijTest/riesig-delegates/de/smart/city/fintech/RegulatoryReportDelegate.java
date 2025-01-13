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
    public boolean hasPermission(RegulatoryReport caller, String role){
        return false;
    }

    public boolean isCompliant(RegulatoryReport caller){
        return false;
    }

    public LocalDate getLastAuditDate(RegulatoryReport caller){
        return null;
    }

    public void revokeAccess(RegulatoryReport caller, String userId){
        ;
    }

    public boolean encrypt(RegulatoryReport caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(RegulatoryReport caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(RegulatoryReport caller){
        return "";
    }

    public boolean decrypt(RegulatoryReport caller){
        return false;
    }

    public String getAuditor(RegulatoryReport caller){
        return "";
    }

    public void addAuditEntry(RegulatoryReport caller, String entry){
        ;
    }
}