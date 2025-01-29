package de.smart.city.healthcare;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 **/
public class PatientHistory {
    protected static PatientHistoryDelegate delegate;
    protected String patientId;
    protected LocalDateTime visitDate;
    protected String diagnosis;
    protected String treatment;
    protected String notes;

    public boolean isUrgent(){
        return delegate.isUrgent(this);
    }

    public String getPatientId() {
        return this.patientId;
    }

    public void setPatientId(String patientId) {
        this.patientId = patientId;
    }
    public LocalDateTime getVisitDate() {
        return this.visitDate;
    }

    public void setVisitDate(LocalDateTime visitDate) {
        this.visitDate = visitDate;
    }

    public String getDiagnosis() {
        return this.diagnosis;
    }

    public void setDiagnosis(String diagnosis) {
        this.diagnosis = diagnosis;
    }

    public String getTreatment() {
        return this.treatment;
    }

    public void setTreatment(String treatment) {
        this.treatment = treatment;
    }

    public String getNotes() {
        return this.notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PatientHistory entity = (PatientHistory) o;
        return Objects.equals(patientId, entity.patientId)  && Objects.equals(visitDate, entity.visitDate)  && Objects.equals(diagnosis, entity.diagnosis)  && Objects.equals(treatment, entity.treatment)  && Objects.equals(notes, entity.notes) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(patientId, visitDate, diagnosis, treatment, notes);
    }
}