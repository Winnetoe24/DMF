package de.smart.city.healthcare_extended;

import java.time.LocalDate;
import java.util.Objects;

public class Patient {
    protected static PatientDelegate delegate;
    protected String patientId;
    protected PatientStatus status;
    protected MedicalDepartment department;
    protected VitalSigns vitals;
    protected String bloodType;
    protected LocalDate admissionDate;



    public String getPatientId() {
        return this.patientId;
    }

    public void setPatientId(String patientId) {
        this.patientId = patientId;
    }

    public PatientStatus getStatus() {
        return this.status;
    }

    public void setStatus(PatientStatus status) {
        this.status = status;
    }

    public MedicalDepartment getDepartment() {
        return this.department;
    }

    public void setDepartment(MedicalDepartment department) {
        this.department = department;
    }

    public VitalSigns getVitals() {
        return this.vitals;
    }

    public void setVitals(VitalSigns vitals) {
        this.vitals = vitals;
    }

    public String getBloodType() {
        return this.bloodType;
    }

    public void setBloodType(String bloodType) {
        this.bloodType = bloodType;
    }

    public LocalDate getAdmissionDate() {
        return this.admissionDate;
    }

    public void setAdmissionDate(LocalDate admissionDate) {
        this.admissionDate = admissionDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Patient entity = (Patient) o;
        return Objects.equals(patientId, entity.patientId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(patientId);
    }
}