package de.smart.city.climate;

import java.time.LocalDate;
import java.util.Objects;

public class EmissionReport {
    protected static EmissionReportDelegate delegate;
    protected String reportId;
    protected EmissionSource source;
    protected double amount;
    protected String unit;
    protected LocalDate measurementDate;
    protected boolean verified;



    public String getReportId() {
        return this.reportId;
    }

    public void setReportId(String reportId) {
        this.reportId = reportId;
    }

    public EmissionSource getSource() {
        return this.source;
    }

    public void setSource(EmissionSource source) {
        this.source = source;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getUnit() {
        return this.unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public LocalDate getMeasurementDate() {
        return this.measurementDate;
    }

    public void setMeasurementDate(LocalDate measurementDate) {
        this.measurementDate = measurementDate;
    }

    public boolean getVerified() {
        return this.verified;
    }

    public void setVerified(boolean verified) {
        this.verified = verified;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EmissionReport entity = (EmissionReport) o;
        return Objects.equals(reportId, entity.reportId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(reportId);
    }
}