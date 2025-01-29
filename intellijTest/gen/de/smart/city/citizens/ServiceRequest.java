package de.smart.city.citizens;

import java.time.LocalDateTime;
import java.util.Objects;

public class ServiceRequest {
    protected static ServiceRequestDelegate delegate;
    protected String requestId;
    protected ServiceType type;
    protected Citizen requester;
    protected LocalDateTime submissionTime;
    protected String status;
    protected String description;



    public String getRequestId() {
        return this.requestId;
    }

    public void setRequestId(String requestId) {
        this.requestId = requestId;
    }

    public ServiceType getType() {
        return this.type;
    }

    public void setType(ServiceType type) {
        this.type = type;
    }

    public Citizen getRequester() {
        return this.requester;
    }

    public void setRequester(Citizen requester) {
        this.requester = requester;
    }

    public LocalDateTime getSubmissionTime() {
        return this.submissionTime;
    }

    public void setSubmissionTime(LocalDateTime submissionTime) {
        this.submissionTime = submissionTime;
    }

    public String getStatus() {
        return this.status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ServiceRequest entity = (ServiceRequest) o;
        return Objects.equals(requestId, entity.requestId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(requestId);
    }
}