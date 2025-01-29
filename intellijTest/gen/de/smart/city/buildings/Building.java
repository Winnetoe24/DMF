package de.smart.city.buildings;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Building extends Asset {
    protected static BuildingDelegate delegate;
    protected BuildingType type;
    protected int floors;
    protected double totalArea;
    protected int occupancy;
    protected SecurityLevel securityLevel;
    protected boolean isSmartEnabled;



    public BuildingType getType() {
        return this.type;
    }

    public void setType(BuildingType type) {
        this.type = type;
    }

    public int getFloors() {
        return this.floors;
    }

    public void setFloors(int floors) {
        this.floors = floors;
    }

    public double getTotalArea() {
        return this.totalArea;
    }

    public void setTotalArea(double totalArea) {
        this.totalArea = totalArea;
    }

    public int getOccupancy() {
        return this.occupancy;
    }

    public void setOccupancy(int occupancy) {
        this.occupancy = occupancy;
    }

    public SecurityLevel getSecurityLevel() {
        return this.securityLevel;
    }

    public void setSecurityLevel(SecurityLevel securityLevel) {
        this.securityLevel = securityLevel;
    }

    public boolean getIsSmartEnabled() {
        return this.isSmartEnabled;
    }

    public void setIsSmartEnabled(boolean isSmartEnabled) {
        this.isSmartEnabled = isSmartEnabled;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Building entity = (Building) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}