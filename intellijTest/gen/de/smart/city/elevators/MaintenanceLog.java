package de.smart.city.elevators;

import java.time.LocalDateTime;
import java.util.Objects;

public class MaintenanceLog {
    protected static MaintenanceLogDelegate delegate;
    protected String logId;
    protected Elevator elevator;
    protected LocalDateTime serviceTime;
    protected String technician;
    protected String work;
    protected boolean resolved;



    public String getLogId() {
        return this.logId;
    }

    public void setLogId(String logId) {
        this.logId = logId;
    }

    public Elevator getElevator() {
        return this.elevator;
    }

    public void setElevator(Elevator elevator) {
        this.elevator = elevator;
    }

    public LocalDateTime getServiceTime() {
        return this.serviceTime;
    }

    public void setServiceTime(LocalDateTime serviceTime) {
        this.serviceTime = serviceTime;
    }

    public String getTechnician() {
        return this.technician;
    }

    public void setTechnician(String technician) {
        this.technician = technician;
    }

    public String getWork() {
        return this.work;
    }

    public void setWork(String work) {
        this.work = work;
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
        MaintenanceLog entity = (MaintenanceLog) o;
        return Objects.equals(logId, entity.logId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(logId);
    }
}