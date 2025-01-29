package de.smart.city.bathrooms;

import java.time.LocalDateTime;
import java.util.Objects;

public class MaintenanceTicket {
    protected static MaintenanceTicketDelegate delegate;
    protected String ticketId;
    protected PublicBathroom bathroom;
    protected String issue;
    protected LocalDateTime reportTime;
    protected boolean isUrgent;
    protected boolean resolved;



    public String getTicketId() {
        return this.ticketId;
    }

    public void setTicketId(String ticketId) {
        this.ticketId = ticketId;
    }

    public PublicBathroom getBathroom() {
        return this.bathroom;
    }

    public void setBathroom(PublicBathroom bathroom) {
        this.bathroom = bathroom;
    }

    public String getIssue() {
        return this.issue;
    }

    public void setIssue(String issue) {
        this.issue = issue;
    }

    public LocalDateTime getReportTime() {
        return this.reportTime;
    }

    public void setReportTime(LocalDateTime reportTime) {
        this.reportTime = reportTime;
    }

    public boolean getIsUrgent() {
        return this.isUrgent;
    }

    public void setIsUrgent(boolean isUrgent) {
        this.isUrgent = isUrgent;
    }

    public boolean getResolved() {
        return this.resolved;
    }

    public void setResolved(boolean resolved) {
        this.resolved = resolved;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MaintenanceTicket entity = (MaintenanceTicket) o;
        return Objects.equals(ticketId, entity.ticketId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(ticketId);
    }
}