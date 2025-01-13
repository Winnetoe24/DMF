package de.smart.city.fintech;

import java.time.LocalDate;
import de.smart.city.infrastructure.AssetStatus;
import de.smart.city.infrastructure.GeoLocation;

/**
 * Delegate von FinancialInstitution * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class FinancialInstitutionDelegate {
    static {
        FinancialInstitution.delegate = new FinancialInstitutionDelegate();
    }
    public void revokeAccess(FinancialInstitution caller, String userId){
        ;
    }

    public boolean isCompliant(FinancialInstitution caller){
        return false;
    }

    public boolean hasPermission(FinancialInstitution caller, String role){
        return false;
    }

    public String getAuditor(FinancialInstitution caller){
        return "";
    }

    /**
     * TODO []
     **/
    public String getAuditTrail(FinancialInstitution caller){
        return "";
    }

    public void addAuditEntry(FinancialInstitution caller, String entry){
        ;
    }

    public LocalDate getLastAuditDate(FinancialInstitution caller){
        return null;
    }

    public boolean encrypt(FinancialInstitution caller){
        return false;
    }

    public boolean decrypt(FinancialInstitution caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(FinancialInstitution caller){
        return "";
    }
}