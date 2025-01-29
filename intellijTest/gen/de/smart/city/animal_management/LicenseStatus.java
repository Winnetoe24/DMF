package de.smart.city.animal_management;

/**
 **/
public enum LicenseStatus {
    ACTIVE(),
    EXPIRED(),
    PENDING(),
    REVOKED(),
    TEMPORARY();


    LicenseStatus(){
        
    }
}