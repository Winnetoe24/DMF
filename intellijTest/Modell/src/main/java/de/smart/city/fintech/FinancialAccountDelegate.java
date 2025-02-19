package de.smart.city.fintech;

import java.time.LocalDate;

/**
 * Delegate von FinancialAccount * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FinancialAccountDelegate {
    static {
        FinancialAccount.delegate = new FinancialAccountDelegate();
    }
    public String getAuditor(FinancialAccount caller){
        return "";
    }

    public double calculateFees(FinancialAccount caller){
        return 0d;
    }

    public LocalDate getLastAuditDate(FinancialAccount caller){
        return null;
    }

    public boolean decrypt(FinancialAccount caller){
        return false;
    }

    public boolean validate(FinancialAccount caller){
        return false;
    }

    public boolean verifySignature(FinancialAccount caller, String signature){
        return false;
    }

    public boolean encrypt(FinancialAccount caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(FinancialAccount caller){
        return "";
    }

    public boolean isCompliant(FinancialAccount caller){
        return false;
    }

    public void revokeAccess(FinancialAccount caller, String userId){
        ;
    }

    public String generateHash(FinancialAccount caller){
        return "";
    }

    public void logTransaction(FinancialAccount caller){
        ;
    }

    public boolean hasPermission(FinancialAccount caller, String role){
        return false;
    }

    public void addAuditEntry(FinancialAccount caller, String entry){
        ;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(FinancialAccount caller){
        return "";
    }
}