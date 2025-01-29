package de.library.management.verification;

/**
 * Status der Verifikation
 **/
public enum VerificationStatus {
    PENDING(),
    VERIFIED(),
    REJECTED(),
    EXPIRED(),
    SUSPENDED();


    VerificationStatus(){
        
    }
}