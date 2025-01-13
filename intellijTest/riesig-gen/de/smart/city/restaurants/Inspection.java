package de.smart.city.restaurants;

import java.time.LocalDate;
import java.util.Objects;

public class Inspection {
    protected static InspectionDelegate delegate;
    protected String inspectionId;
    protected Restaurant restaurant;
    protected LocalDate inspectionDate;
    protected boolean passed;
    protected LocalDate followupDate;



    public String getInspectionId() {
        return this.inspectionId;
    }

    public void setInspectionId(String inspectionId) {
        this.inspectionId = inspectionId;
    }

    public Restaurant getRestaurant() {
        return this.restaurant;
    }

    public void setRestaurant(Restaurant restaurant) {
        this.restaurant = restaurant;
    }

    public LocalDate getInspectionDate() {
        return this.inspectionDate;
    }

    public void setInspectionDate(LocalDate inspectionDate) {
        this.inspectionDate = inspectionDate;
    }

    public boolean getPassed() {
        return this.passed;
    }

    public void setPassed(boolean passed) {
        this.passed = passed;
    }

    public LocalDate getFollowupDate() {
        return this.followupDate;
    }

    public void setFollowupDate(LocalDate followupDate) {
        this.followupDate = followupDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Inspection entity = (Inspection) o;
        return Objects.equals(inspectionId, entity.inspectionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(inspectionId);
    }
}