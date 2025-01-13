package de.smart.city.urbanplanning;

import java.time.LocalDate;
import java.util.Objects;

public class DevelopmentProject {
    protected static DevelopmentProjectDelegate delegate;
    protected String projectId;
    protected DevelopmentStatus status;
    protected String description;
    protected LocalDate startDate;
    protected LocalDate completionDate;
    protected double budget;



    public String getProjectId() {
        return this.projectId;
    }

    public void setProjectId(String projectId) {
        this.projectId = projectId;
    }

    public DevelopmentStatus getStatus() {
        return this.status;
    }

    public void setStatus(DevelopmentStatus status) {
        this.status = status;
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

    public LocalDate getCompletionDate() {
        return this.completionDate;
    }

    public void setCompletionDate(LocalDate completionDate) {
        this.completionDate = completionDate;
    }

    public double getBudget() {
        return this.budget;
    }

    public void setBudget(double budget) {
        this.budget = budget;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        DevelopmentProject entity = (DevelopmentProject) o;
        return Objects.equals(projectId, entity.projectId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(projectId);
    }
}