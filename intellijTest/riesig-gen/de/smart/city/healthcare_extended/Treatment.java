package de.smart.city.healthcare_extended;

import java.time.LocalDateTime;
import java.util.Objects;

public class Treatment {
    protected static TreatmentDelegate delegate;
    protected String treatmentId;
    protected TreatmentType type;
    protected Patient patient;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String provider;
    protected String notes;
    protected boolean completed;



    public String getTreatmentId() {
        return this.treatmentId;
    }

    public void setTreatmentId(String treatmentId) {
        this.treatmentId = treatmentId;
    }

    public TreatmentType getType() {
        return this.type;
    }

    public void setType(TreatmentType type) {
        this.type = type;
    }

    public Patient getPatient() {
        return this.patient;
    }

    public void setPatient(Patient patient) {
        this.patient = patient;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getEndTime() {
        return this.endTime;
    }

    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    public String getProvider() {
        return this.provider;
    }

    public void setProvider(String provider) {
        this.provider = provider;
    }

    public String getNotes() {
        return this.notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }

    public boolean getCompleted() {
        return this.completed;
    }

    public void setCompleted(boolean completed) {
        this.completed = completed;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Treatment entity = (Treatment) o;
        return Objects.equals(treatmentId, entity.treatmentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(treatmentId);
    }
}