package de.smart.city.wildlife;

import java.time.LocalDate;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class WildlifeZone extends Asset {
    protected static WildlifeZoneDelegate delegate;
    protected HabitatType type;
    protected double area;
    protected boolean isProtected;
    protected LocalDate lastSurvey;



    public HabitatType getType() {
        return this.type;
    }

    public void setType(HabitatType type) {
        this.type = type;
    }

    public double getArea() {
        return this.area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public boolean getIsProtected() {
        return this.isProtected;
    }

    public void setIsProtected(boolean isProtected) {
        this.isProtected = isProtected;
    }

    public LocalDate getLastSurvey() {
        return this.lastSurvey;
    }

    public void setLastSurvey(LocalDate lastSurvey) {
        this.lastSurvey = lastSurvey;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WildlifeZone entity = (WildlifeZone) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}