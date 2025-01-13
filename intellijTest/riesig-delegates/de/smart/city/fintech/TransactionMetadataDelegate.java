package de.smart.city.fintech;

import java.time.LocalDateTime;

/**
 * Delegate von TransactionMetadata * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class TransactionMetadataDelegate {
    static {
        TransactionMetadata.delegate = new TransactionMetadataDelegate();
    }
    public boolean encrypt(TransactionMetadata caller){
        return false;
    }

    public java.time.LocalDate getLastAuditDate(TransactionMetadata caller){
        return null;
    }

    public boolean hasPermission(TransactionMetadata caller, String role){
        return false;
    }

    public boolean validate(TransactionMetadata caller){
        return false;
    }

    public String getAuditor(TransactionMetadata caller){
        return "";
    }

    public void addAuditEntry(TransactionMetadata caller, String entry){
        ;
    }

    public boolean isCompliant(TransactionMetadata caller){
        return false;
    }

    public boolean decrypt(TransactionMetadata caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(TransactionMetadata caller){
        return "";
    }

    public void revokeAccess(TransactionMetadata caller, String userId){
        ;
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(TransactionMetadata caller){
        return "";
    }
}