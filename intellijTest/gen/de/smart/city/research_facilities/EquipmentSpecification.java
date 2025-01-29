package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 **/
public class EquipmentSpecification {
    protected static EquipmentSpecificationDelegate delegate;
    protected double precision;
    protected double accuracy;
    /**
     * TODO []
     **/
    protected String calibrationRequirements;
    /**
     * TODO []
     **/
    protected String operatingConditions;
    protected LocalDateTime lastVerification;

    public boolean needsCalibration(){
        return delegate.needsCalibration(this);
    }

    public boolean meetsStandards(){
        return delegate.meetsStandards(this);
    }

    public double getPrecision() {
        return this.precision;
    }

    public void setPrecision(double precision) {
        this.precision = precision;
    }

    public double getAccuracy() {
        return this.accuracy;
    }

    public void setAccuracy(double accuracy) {
        this.accuracy = accuracy;
    }
    /**
     * TODO []
     **/
    public String getCalibrationRequirements() {
        return this.calibrationRequirements;
    }

    /**
     * TODO []
     **/
    public void setCalibrationRequirements(String calibrationRequirements) {
        this.calibrationRequirements = calibrationRequirements;
    }

    /**
     * TODO []
     **/
    public String getOperatingConditions() {
        return this.operatingConditions;
    }

    /**
     * TODO []
     **/
    public void setOperatingConditions(String operatingConditions) {
        this.operatingConditions = operatingConditions;
    }

    public LocalDateTime getLastVerification() {
        return this.lastVerification;
    }

    public void setLastVerification(LocalDateTime lastVerification) {
        this.lastVerification = lastVerification;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EquipmentSpecification entity = (EquipmentSpecification) o;
        return Objects.equals(precision, entity.precision)  && Objects.equals(accuracy, entity.accuracy)  && Objects.equals(calibrationRequirements, entity.calibrationRequirements)  && Objects.equals(operatingConditions, entity.operatingConditions)  && Objects.equals(lastVerification, entity.lastVerification) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(precision, accuracy, calibrationRequirements, operatingConditions, lastVerification);
    }
}