package de.smart.city.research_facilities;

import java.time.LocalDate;

/**
 * Delegate von ResearchMetadata * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ResearchMetadataDelegate {
    static {
        ResearchMetadata.delegate = new ResearchMetadataDelegate();
    }
    public double calculateProgress(ResearchMetadata caller){
        return 0d;
    }

    public boolean isActive(ResearchMetadata caller){
        return false;
    }

    /**
     * TODO [] return
     **/
    public String getCollaborators(ResearchMetadata caller){
        return "";
    }
}