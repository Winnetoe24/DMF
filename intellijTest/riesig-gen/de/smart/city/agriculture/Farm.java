package de.smart.city.agriculture;

import java.time.LocalDate;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Farm extends Asset {
    protected static FarmDelegate delegate;
    protected double area;
    protected IrrigationType irrigationType;
    protected boolean isOrganic;
    protected LocalDate lastHarvestDate;



    public double getArea() {
        return this.area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public IrrigationType getIrrigationType() {
        return this.irrigationType;
    }

    public void setIrrigationType(IrrigationType irrigationType) {
        this.irrigationType = irrigationType;
    }

    public boolean getIsOrganic() {
        return this.isOrganic;
    }

    public void setIsOrganic(boolean isOrganic) {
        this.isOrganic = isOrganic;
    }

    public LocalDate getLastHarvestDate() {
        return this.lastHarvestDate;
    }

    public void setLastHarvestDate(LocalDate lastHarvestDate) {
        this.lastHarvestDate = lastHarvestDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Farm entity = (Farm) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}