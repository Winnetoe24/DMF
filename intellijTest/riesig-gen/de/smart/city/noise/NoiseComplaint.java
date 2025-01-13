package de.smart.city.noise;

import java.time.LocalDateTime;
import java.util.Objects;

public class NoiseComplaint {
    protected static NoiseComplaintDelegate delegate;
    protected String complaintId;
    protected NoiseSource source;
    protected LocalDateTime reportTime;
    protected String description;
    protected boolean isResolved;
    protected String resolution;



    public String getComplaintId() {
        return this.complaintId;
    }

    public void setComplaintId(String complaintId) {
        this.complaintId = complaintId;
    }

    public NoiseSource getSource() {
        return this.source;
    }

    public void setSource(NoiseSource source) {
        this.source = source;
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

    public boolean getIsResolved() {
        return this.isResolved;
    }

    public void setIsResolved(boolean isResolved) {
        this.isResolved = isResolved;
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
        NoiseComplaint entity = (NoiseComplaint) o;
        return Objects.equals(complaintId, entity.complaintId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(complaintId);
    }
}