package de.smart.city.research_facilities;

import java.time.LocalDate;
import java.util.Objects;

public class SafetyProtocol {
    protected static SafetyProtocolDelegate delegate;
    protected String protocolId;
    protected Laboratory lab;
    protected String hazardType;
    protected LocalDate lastReview;
    protected boolean requiresTraining;



    public String getProtocolId() {
        return this.protocolId;
    }

    public void setProtocolId(String protocolId) {
        this.protocolId = protocolId;
    }

    public Laboratory getLab() {
        return this.lab;
    }

    public void setLab(Laboratory lab) {
        this.lab = lab;
    }

    public String getHazardType() {
        return this.hazardType;
    }

    public void setHazardType(String hazardType) {
        this.hazardType = hazardType;
    }

    public LocalDate getLastReview() {
        return this.lastReview;
    }

    public void setLastReview(LocalDate lastReview) {
        this.lastReview = lastReview;
    }

    public boolean getRequiresTraining() {
        return this.requiresTraining;
    }

    public void setRequiresTraining(boolean requiresTraining) {
        this.requiresTraining = requiresTraining;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SafetyProtocol entity = (SafetyProtocol) o;
        return Objects.equals(protocolId, entity.protocolId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(protocolId);
    }
}