package de.smart.city.urbanplanning;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Zone extends Asset {
    protected static ZoneDelegate delegate;
    protected ZoneType type;
    protected double area;
    protected double maxDensity;
    protected int heightLimit;
    protected boolean isHistorical;



    public ZoneType getType() {
        return this.type;
    }

    public void setType(ZoneType type) {
        this.type = type;
    }

    public double getArea() {
        return this.area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double getMaxDensity() {
        return this.maxDensity;
    }

    public void setMaxDensity(double maxDensity) {
        this.maxDensity = maxDensity;
    }

    public int getHeightLimit() {
        return this.heightLimit;
    }

    public void setHeightLimit(int heightLimit) {
        this.heightLimit = heightLimit;
    }

    public boolean getIsHistorical() {
        return this.isHistorical;
    }

    public void setIsHistorical(boolean isHistorical) {
        this.isHistorical = isHistorical;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Zone entity = (Zone) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}