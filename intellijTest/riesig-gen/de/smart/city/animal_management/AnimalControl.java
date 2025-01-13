package de.smart.city.animal_management;

import java.time.LocalDateTime;
import java.util.Objects;

public class AnimalControl {
    protected static AnimalControlDelegate delegate;
    protected String caseId;
    protected PetType animalType;
    protected LocalDateTime reportTime;
    protected String incidentType;
    protected String location;
    protected boolean resolved;
    protected String resolution;



    public String getCaseId() {
        return this.caseId;
    }

    public void setCaseId(String caseId) {
        this.caseId = caseId;
    }

    public PetType getAnimalType() {
        return this.animalType;
    }

    public void setAnimalType(PetType animalType) {
        this.animalType = animalType;
    }

    public LocalDateTime getReportTime() {
        return this.reportTime;
    }

    public void setReportTime(LocalDateTime reportTime) {
        this.reportTime = reportTime;
    }

    public String getIncidentType() {
        return this.incidentType;
    }

    public void setIncidentType(String incidentType) {
        this.incidentType = incidentType;
    }

    public String getLocation() {
        return this.location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public boolean getResolved() {
        return this.resolved;
    }

    public void setResolved(boolean resolved) {
        this.resolved = resolved;
    }

    public String getResolution() {
        return this.resolution;
    }

    public void setResolution(String resolution) {
        this.resolution = resolution;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AnimalControl entity = (AnimalControl) o;
        return Objects.equals(caseId, entity.caseId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(caseId);
    }
}