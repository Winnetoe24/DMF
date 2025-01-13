package de.smart.city.wildlife;

import java.time.LocalDateTime;
import java.util.Objects;

public class WildlifeIncident {
    protected static WildlifeIncidentDelegate delegate;
    protected String incidentId;
    protected SpeciesType species;
    protected LocalDateTime reportTime;
    protected String description;
    protected boolean requiresAction;
    protected String resolution;



    public String getIncidentId() {
        return this.incidentId;
    }

    public void setIncidentId(String incidentId) {
        this.incidentId = incidentId;
    }

    public SpeciesType getSpecies() {
        return this.species;
    }

    public void setSpecies(SpeciesType species) {
        this.species = species;
    }

    public LocalDateTime getReportTime() {
        return this.reportTime;
    }

    public void setReportTime(LocalDateTime reportTime) {
        this.reportTime = reportTime;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public boolean getRequiresAction() {
        return this.requiresAction;
    }

    public void setRequiresAction(boolean requiresAction) {
        this.requiresAction = requiresAction;
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
        WildlifeIncident entity = (WildlifeIncident) o;
        return Objects.equals(incidentId, entity.incidentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(incidentId);
    }
}