package de.smart.city.fintech;

import java.time.LocalDateTime;

/**
 * Delegate von AuditLog * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AuditLogDelegate {
    static {
        AuditLog.delegate = new AuditLogDelegate();
    }
    public void addAuditEntry(AuditLog caller, String entry){
        ;
    }

    public java.time.LocalDate getLastAuditDate(AuditLog caller){
        return null;
    }

    public String getAuditor(AuditLog caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(AuditLog caller){
        return "";
    }

    public boolean isCompliant(AuditLog caller){
        return false;
    }
}