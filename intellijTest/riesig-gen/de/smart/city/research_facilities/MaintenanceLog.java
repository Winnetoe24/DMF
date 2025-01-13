package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import java.util.Objects;

public class MaintenanceLog {
    protected static MaintenanceLogDelegate delegate;
    protected String logId;
    protected ResearchEquipment equipment;
    protected LocalDateTime maintenanceTime;
    protected String technician;
    protected double cost;
    protected boolean requiresFollowup;



    public String getLogId() {
        return this.logId;
    }

    public void setLogId(String logId) {
        this.logId = logId;
    }

    public ResearchEquipment getEquipment() {
        return this.equipment;
    }

    public void setEquipment(ResearchEquipment equipment) {
        this.equipment = equipment;
    }

    public LocalDateTime getMaintenanceTime() {
        return this.maintenanceTime;
    }

    public void setMaintenanceTime(LocalDateTime maintenanceTime) {
        this.maintenanceTime = maintenanceTime;
    }

    public String getTechnician() {
        return this.technician;
    }

    public void setTechnician(String technician) {
        this.technician = technician;
    }

    public double getCost() {
        return this.cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public boolean getRequiresFollowup() {
        return this.requiresFollowup;
    }

    public void setRequiresFollowup(boolean requiresFollowup) {
        this.requiresFollowup = requiresFollowup;
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