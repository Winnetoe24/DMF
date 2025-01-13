package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import java.util.Objects;

public class Experiment {
    protected static ExperimentDelegate delegate;
    protected String experimentId;
    protected ExperimentalPhase phase;
    protected ResearchMetadata metadata;
    protected Laboratory location;
    protected LocalDateTime scheduledStart;
    protected LocalDateTime scheduledEnd;
    /**
     * TODO []
     **/
    protected String prerequisites;
    protected String dependencies;
    protected boolean hasEthicalApproval;



    public String getExperimentId() {
        return this.experimentId;
    }

    public void setExperimentId(String experimentId) {
        this.experimentId = experimentId;
    }

    public ExperimentalPhase getPhase() {
        return this.phase;
    }

    public void setPhase(ExperimentalPhase phase) {
        this.phase = phase;
    }

    public ResearchMetadata getMetadata() {
        return this.metadata;
    }

    public void setMetadata(ResearchMetadata metadata) {
        this.metadata = metadata;
    }

    public Laboratory getLocation() {
        return this.location;
    }

    public void setLocation(Laboratory location) {
        this.location = location;
    }

    public LocalDateTime getScheduledStart() {
        return this.scheduledStart;
    }

    public void setScheduledStart(LocalDateTime scheduledStart) {
        this.scheduledStart = scheduledStart;
    }

    public LocalDateTime getScheduledEnd() {
        return this.scheduledEnd;
    }

    public void setScheduledEnd(LocalDateTime scheduledEnd) {
        this.scheduledEnd = scheduledEnd;
    }

    /**
     * TODO []
     **/
    public String getPrerequisites() {
        return this.prerequisites;
    }

    /**
     * TODO []
     **/
    public void setPrerequisites(String prerequisites) {
        this.prerequisites = prerequisites;
    }

    public String getDependencies() {
        return this.dependencies;
    }

    public void setDependencies(String dependencies) {
        this.dependencies = dependencies;
    }

    public boolean getHasEthicalApproval() {
        return this.hasEthicalApproval;
    }

    public void setHasEthicalApproval(boolean hasEthicalApproval) {
        this.hasEthicalApproval = hasEthicalApproval;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Experiment entity = (Experiment) o;
        return Objects.equals(experimentId, entity.experimentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(experimentId);
    }
}