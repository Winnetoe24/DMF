package de.smart.city.safety;

import java.time.LocalDateTime;
import java.util.Objects;

public class SafetyIncident {
    protected static SafetyIncidentDelegate delegate;
    protected String incidentId;
    protected IncidentType type;
    protected LocalDateTime reportTime;
    protected String description;
    protected boolean requiresEvacuation;



    public String getIncidentId() {
        return this.incidentId;
    }

    public void setIncidentId(String incidentId) {
        this.incidentId = incidentId;
    }

    public IncidentType getType() {
        return this.type;
    }

    public void setType(IncidentType type) {
        this.type = type;
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

    public boolean getRequiresEvacuation() {
        return this.requiresEvacuation;
    }

    public void setRequiresEvacuation(boolean requiresEvacuation) {
        this.requiresEvacuation = requiresEvacuation;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SafetyIncident entity = (SafetyIncident) o;
        return Objects.equals(incidentId, entity.incidentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(incidentId);
    }
}