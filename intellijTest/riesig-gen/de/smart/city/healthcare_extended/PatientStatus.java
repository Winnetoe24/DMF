package de.smart.city.healthcare_extended;

/**
 **/
public enum PatientStatus {
    ADMITTED(),
    OUTPATIENT(),
    CRITICAL(),
    STABLE(),
    DISCHARGED(),
    TRANSFERRED(),
    QUARANTINE(),
    OBSERVATION(),
    RECOVERY(),
    EMERGENCY();


    PatientStatus(){
        
    }
}