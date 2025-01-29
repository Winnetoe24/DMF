package de.smart.city.infrastructure;

import java.time.LocalDate;
import java.util.Objects;

public class Asset {
    protected static AssetDelegate delegate;
    protected String assetId;
    protected String name;
    protected GeoLocation location;
    protected AssetStatus status;
    protected LocalDate installationDate;
    protected LocalDate lastMaintenanceDate;
    protected double acquisitionCost;
    protected int expectedLifespanYears;



    public String getAssetId() {
        return this.assetId;
    }

    public void setAssetId(String assetId) {
        this.assetId = assetId;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public GeoLocation getLocation() {
        return this.location;
    }

    public void setLocation(GeoLocation location) {
        this.location = location;
    }

    public AssetStatus getStatus() {
        return this.status;
    }

    public void setStatus(AssetStatus status) {
        this.status = status;
    }

    public LocalDate getInstallationDate() {
        return this.installationDate;
    }

    public void setInstallationDate(LocalDate installationDate) {
        this.installationDate = installationDate;
    }

    public LocalDate getLastMaintenanceDate() {
        return this.lastMaintenanceDate;
    }

    public void setLastMaintenanceDate(LocalDate lastMaintenanceDate) {
        this.lastMaintenanceDate = lastMaintenanceDate;
    }

    public double getAcquisitionCost() {
        return this.acquisitionCost;
    }

    public void setAcquisitionCost(double acquisitionCost) {
        this.acquisitionCost = acquisitionCost;
    }

    public int getExpectedLifespanYears() {
        return this.expectedLifespanYears;
    }

    public void setExpectedLifespanYears(int expectedLifespanYears) {
        this.expectedLifespanYears = expectedLifespanYears;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Asset entity = (Asset) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}