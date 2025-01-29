package de.smart.city.cemetery;

import java.time.LocalDate;
import java.util.Objects;

public class Plot {
    protected static PlotDelegate delegate;
    protected String plotId;
    protected PlotType type;
    protected MaintenanceSchedule schedule;
    protected LocalDate lastMaintenance;
    protected boolean isOccupied;
    protected String owner;



    public String getPlotId() {
        return this.plotId;
    }

    public void setPlotId(String plotId) {
        this.plotId = plotId;
    }

    public PlotType getType() {
        return this.type;
    }

    public void setType(PlotType type) {
        this.type = type;
    }

    public MaintenanceSchedule getSchedule() {
        return this.schedule;
    }

    public void setSchedule(MaintenanceSchedule schedule) {
        this.schedule = schedule;
    }

    public LocalDate getLastMaintenance() {
        return this.lastMaintenance;
    }

    public void setLastMaintenance(LocalDate lastMaintenance) {
        this.lastMaintenance = lastMaintenance;
    }

    public boolean getIsOccupied() {
        return this.isOccupied;
    }

    public void setIsOccupied(boolean isOccupied) {
        this.isOccupied = isOccupied;
    }

    public String getOwner() {
        return this.owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Plot entity = (Plot) o;
        return Objects.equals(plotId, entity.plotId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(plotId);
    }
}