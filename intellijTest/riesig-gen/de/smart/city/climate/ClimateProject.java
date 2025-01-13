package de.smart.city.climate;

import java.time.LocalDate;
import java.util.Objects;

public class ClimateProject {
    protected static ClimateProjectDelegate delegate;
    protected String projectId;
    protected MitigationStrategy strategy;
    protected String description;
    protected LocalDate startDate;
    protected double budget;
    protected boolean isActive;



    public String getProjectId() {
        return this.projectId;
    }

    public void setProjectId(String projectId) {
        this.projectId = projectId;
    }

    public MitigationStrategy getStrategy() {
        return this.strategy;
    }

    public void setStrategy(MitigationStrategy strategy) {
        this.strategy = strategy;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public LocalDate getStartDate() {
        return this.startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public double getBudget() {
        return this.budget;
    }

    public void setBudget(double budget) {
        this.budget = budget;
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
        ClimateProject entity = (ClimateProject) o;
        return Objects.equals(projectId, entity.projectId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(projectId);
    }
}