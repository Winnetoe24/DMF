package de.smart.city.manufacturing;

import java.time.LocalDate;
import java.util.Objects;

/**
 **/
public class MaintenanceSchedule {
    protected static MaintenanceScheduleDelegate delegate;
    protected LocalDate lastMaintenance;
    protected LocalDate nextMaintenance;
    protected int frequency;
    /**
     * TODO []
     **/
    protected String tasks;
    protected String responsible;

    public boolean isOverdue(){
        return delegate.isOverdue(this);
    }

    public LocalDate getLastMaintenance() {
        return this.lastMaintenance;
    }

    public void setLastMaintenance(LocalDate lastMaintenance) {
        this.lastMaintenance = lastMaintenance;
    }
    public LocalDate getNextMaintenance() {
        return this.nextMaintenance;
    }

    public void setNextMaintenance(LocalDate nextMaintenance) {
        this.nextMaintenance = nextMaintenance;
    }

    public int getFrequency() {
        return this.frequency;
    }

    public void setFrequency(int frequency) {
        this.frequency = frequency;
    }

    /**
     * TODO []
     **/
    public String getTasks() {
        return this.tasks;
    }

    /**
     * TODO []
     **/
    public void setTasks(String tasks) {
        this.tasks = tasks;
    }

    public String getResponsible() {
        return this.responsible;
    }

    public void setResponsible(String responsible) {
        this.responsible = responsible;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MaintenanceSchedule entity = (MaintenanceSchedule) o;
        return Objects.equals(tasks, entity.tasks)  && Objects.equals(responsible, entity.responsible)  && Objects.equals(lastMaintenance, entity.lastMaintenance)  && Objects.equals(nextMaintenance, entity.nextMaintenance)  && Objects.equals(frequency, entity.frequency) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(tasks, responsible, lastMaintenance, nextMaintenance, frequency);
    }
}