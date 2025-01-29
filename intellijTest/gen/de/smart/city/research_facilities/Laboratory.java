package de.smart.city.research_facilities;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Laboratory extends Asset {
    protected static LaboratoryDelegate delegate;
    /**
     * TODO []
     **/
    protected ResearchDomain domains;
    protected DataClassification securityLevel;
    /**
     * TODO []
     **/
    protected String specializations;
    protected double totalArea;
    protected int workstationCount;
    protected boolean hasCleanRoom;
    /**
     * TODO []
     **/
    protected String safetyProtocols;
    /**
     * TODO []
     **/
    protected String certifications;



    /**
     * TODO []
     **/
    public ResearchDomain getDomains() {
        return this.domains;
    }

    /**
     * TODO []
     **/
    public void setDomains(ResearchDomain domains) {
        this.domains = domains;
    }

    public DataClassification getSecurityLevel() {
        return this.securityLevel;
    }

    public void setSecurityLevel(DataClassification securityLevel) {
        this.securityLevel = securityLevel;
    }

    /**
     * TODO []
     **/
    public String getSpecializations() {
        return this.specializations;
    }

    /**
     * TODO []
     **/
    public void setSpecializations(String specializations) {
        this.specializations = specializations;
    }

    public double getTotalArea() {
        return this.totalArea;
    }

    public void setTotalArea(double totalArea) {
        this.totalArea = totalArea;
    }

    public int getWorkstationCount() {
        return this.workstationCount;
    }

    public void setWorkstationCount(int workstationCount) {
        this.workstationCount = workstationCount;
    }

    public boolean getHasCleanRoom() {
        return this.hasCleanRoom;
    }

    public void setHasCleanRoom(boolean hasCleanRoom) {
        this.hasCleanRoom = hasCleanRoom;
    }

    /**
     * TODO []
     **/
    public String getSafetyProtocols() {
        return this.safetyProtocols;
    }

    /**
     * TODO []
     **/
    public void setSafetyProtocols(String safetyProtocols) {
        this.safetyProtocols = safetyProtocols;
    }

    /**
     * TODO []
     **/
    public String getCertifications() {
        return this.certifications;
    }

    /**
     * TODO []
     **/
    public void setCertifications(String certifications) {
        this.certifications = certifications;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Laboratory entity = (Laboratory) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}