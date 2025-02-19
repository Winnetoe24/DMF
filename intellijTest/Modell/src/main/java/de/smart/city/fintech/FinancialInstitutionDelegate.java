package de.smart.city.fintech;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import de.smart.city.infrastructure.AssetStatus;

/**
 * Delegate von FinancialInstitution * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FinancialInstitutionDelegate {
    static {
        FinancialInstitution.delegate = new FinancialInstitutionDelegate();
    }
    /**
     * TODO []
     **/
    public String getAuditTrail(FinancialInstitution caller){
        return "";
    }

    public boolean hasPermission(FinancialInstitution caller, String role){
        return false;
    }

    public void revokeAccess(FinancialInstitution caller, String userId){
        ;
    }

    public void addAuditEntry(FinancialInstitution caller, String entry){
        ;
    }

    public boolean isCompliant(FinancialInstitution caller){
        return false;
    }

    public LocalDate getLastAuditDate(FinancialInstitution caller){
        return null;
    }

    public boolean encrypt(FinancialInstitution caller){
        return false;
    }

    public String getAuditor(FinancialInstitution caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(FinancialInstitution caller){
        return "";
    }

    public boolean decrypt(FinancialInstitution caller){
        return false;
    }
}