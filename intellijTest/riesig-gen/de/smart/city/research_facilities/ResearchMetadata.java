package de.smart.city.research_facilities;

import java.time.LocalDate;
import java.util.Objects;

/**
 * Abstract base structures for research management
 **/
public class ResearchMetadata {
    protected static ResearchMetadataDelegate delegate;
    /**
     * TODO []
     **/
    protected String keywords;
    /**
     * TODO []
     **/
    protected String classifications;
    protected String methodology;
    protected LocalDate startDate;
    protected LocalDate endDate;

    public boolean isActive(){
        return delegate.isActive(this);
    }

    /**
     * TODO [] return
     **/
    public String getCollaborators(){
        return delegate.getCollaborators(this);
    }

    public double calculateProgress(){
        return delegate.calculateProgress(this);
    }

    /**
     * TODO []
     **/
    public String getKeywords() {
        return this.keywords;
    }

    /**
     * TODO []
     **/
    public void setKeywords(String keywords) {
        this.keywords = keywords;
    }

    /**
     * TODO []
     **/
    public String getClassifications() {
        return this.classifications;
    }

    /**
     * TODO []
     **/
    public void setClassifications(String classifications) {
        this.classifications = classifications;
    }

    public String getMethodology() {
        return this.methodology;
    }

    public void setMethodology(String methodology) {
        this.methodology = methodology;
    }
    public LocalDate getStartDate() {
        return this.startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public LocalDate getEndDate() {
        return this.endDate;
    }

    public void setEndDate(LocalDate endDate) {
        this.endDate = endDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ResearchMetadata entity = (ResearchMetadata) o;
        return Objects.equals(methodology, entity.methodology)  && Objects.equals(startDate, entity.startDate)  && Objects.equals(endDate, entity.endDate)  && Objects.equals(keywords, entity.keywords)  && Objects.equals(classifications, entity.classifications) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(methodology, startDate, endDate, keywords, classifications);
    }
}