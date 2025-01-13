package de.smart.city.emergency;

import de.smart.city.infrastructure.GeoLocation;
import java.time.LocalDateTime;
import java.util.Objects;

public class EmergencyIncident {
    protected static EmergencyIncidentDelegate delegate;
    protected String incidentId;
    protected EmergencyType type;
    protected ResponsePriority priority;
    protected GeoLocation location;
    protected LocalDateTime reportedTime;
    protected LocalDateTime responseTime;
    protected boolean isActive;



    public String getIncidentId() {
        return this.incidentId;
    }

    public void setIncidentId(String incidentId) {
        this.incidentId = incidentId;
    }

    public EmergencyType getType() {
        return this.type;
    }

    public void setType(EmergencyType type) {
        this.type = type;
    }

    public ResponsePriority getPriority() {
        return this.priority;
    }

    public void setPriority(ResponsePriority priority) {
        this.priority = priority;
    }

    public GeoLocation getLocation() {
        return this.location;
    }

    public void setLocation(GeoLocation location) {
        this.location = location;
    }

    public LocalDateTime getReportedTime() {
        return this.reportedTime;
    }

    public void setReportedTime(LocalDateTime reportedTime) {
        this.reportedTime = reportedTime;
    }

    public LocalDateTime getResponseTime() {
        return this.responseTime;
    }

    public void setResponseTime(LocalDateTime responseTime) {
        this.responseTime = responseTime;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EmergencyIncident entity = (EmergencyIncident) o;
        return Objects.equals(incidentId, entity.incidentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(incidentId);
    }
}