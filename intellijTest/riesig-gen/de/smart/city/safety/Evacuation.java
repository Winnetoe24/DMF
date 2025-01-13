package de.smart.city.safety;

import java.time.LocalDateTime;
import java.util.Objects;

public class Evacuation {
    protected static EvacuationDelegate delegate;
    protected String evacuationId;
    protected SafetyIncident incident;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected int affectedPopulation;
    protected boolean isCompleted;



    public String getEvacuationId() {
        return this.evacuationId;
    }

    public void setEvacuationId(String evacuationId) {
        this.evacuationId = evacuationId;
    }

    public SafetyIncident getIncident() {
        return this.incident;
    }

    public void setIncident(SafetyIncident incident) {
        this.incident = incident;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getEndTime() {
        return this.endTime;
    }

    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    public int getAffectedPopulation() {
        return this.affectedPopulation;
    }

    public void setAffectedPopulation(int affectedPopulation) {
        this.affectedPopulation = affectedPopulation;
    }

    public boolean getIsCompleted() {
        return this.isCompleted;
    }

    public void setIsCompleted(boolean isCompleted) {
        this.isCompleted = isCompleted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Evacuation entity = (Evacuation) o;
        return Objects.equals(evacuationId, entity.evacuationId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(evacuationId);
    }
}