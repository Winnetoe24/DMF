package de.smart.city.media_production;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class FilmLocation extends Asset {
    protected static FilmLocationDelegate delegate;
    protected String locationName;
    protected boolean isIndoor;
    protected double dailyRate;
    protected int maxOccupancy;
    protected boolean hasParking;



    public String getLocationName() {
        return this.locationName;
    }

    public void setLocationName(String locationName) {
        this.locationName = locationName;
    }

    public boolean getIsIndoor() {
        return this.isIndoor;
    }

    public void setIsIndoor(boolean isIndoor) {
        this.isIndoor = isIndoor;
    }

    public double getDailyRate() {
        return this.dailyRate;
    }

    public void setDailyRate(double dailyRate) {
        this.dailyRate = dailyRate;
    }

    public int getMaxOccupancy() {
        return this.maxOccupancy;
    }

    public void setMaxOccupancy(int maxOccupancy) {
        this.maxOccupancy = maxOccupancy;
    }

    public boolean getHasParking() {
        return this.hasParking;
    }

    public void setHasParking(boolean hasParking) {
        this.hasParking = hasParking;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FilmLocation entity = (FilmLocation) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}