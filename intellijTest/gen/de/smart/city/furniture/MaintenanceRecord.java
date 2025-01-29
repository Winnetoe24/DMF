package de.smart.city.furniture;

import java.time.LocalDate;
import java.util.Objects;

public class MaintenanceRecord {
    protected static MaintenanceRecordDelegate delegate;
    protected String recordId;
    protected StreetFurniture furniture;
    protected LocalDate maintenanceDate;
    protected String work;
    protected double cost;
    protected String contractor;



    public String getRecordId() {
        return this.recordId;
    }

    public void setRecordId(String recordId) {
        this.recordId = recordId;
    }

    public StreetFurniture getFurniture() {
        return this.furniture;
    }

    public void setFurniture(StreetFurniture furniture) {
        this.furniture = furniture;
    }

    public LocalDate getMaintenanceDate() {
        return this.maintenanceDate;
    }

    public void setMaintenanceDate(LocalDate maintenanceDate) {
        this.maintenanceDate = maintenanceDate;
    }

    public String getWork() {
        return this.work;
    }

    public void setWork(String work) {
        this.work = work;
    }

    public double getCost() {
        return this.cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public String getContractor() {
        return this.contractor;
    }

    public void setContractor(String contractor) {
        this.contractor = contractor;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MaintenanceRecord entity = (MaintenanceRecord) o;
        return Objects.equals(recordId, entity.recordId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(recordId);
    }
}