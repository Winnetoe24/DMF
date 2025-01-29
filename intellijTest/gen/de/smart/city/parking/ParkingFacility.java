package de.smart.city.parking;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class ParkingFacility extends Asset {
    protected static ParkingFacilityDelegate delegate;
    protected ParkingType type;
    protected int totalSpaces;
    protected int availableSpaces;
    protected double hourlyRate;
    protected boolean hasChargingStations;



    public ParkingType getType() {
        return this.type;
    }

    public void setType(ParkingType type) {
        this.type = type;
    }

    public int getTotalSpaces() {
        return this.totalSpaces;
    }

    public void setTotalSpaces(int totalSpaces) {
        this.totalSpaces = totalSpaces;
    }

    public int getAvailableSpaces() {
        return this.availableSpaces;
    }

    public void setAvailableSpaces(int availableSpaces) {
        this.availableSpaces = availableSpaces;
    }

    public double getHourlyRate() {
        return this.hourlyRate;
    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }

    public boolean getHasChargingStations() {
        return this.hasChargingStations;
    }

    public void setHasChargingStations(boolean hasChargingStations) {
        this.hasChargingStations = hasChargingStations;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ParkingFacility entity = (ParkingFacility) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}