package de.smart.city.cemetery;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Cemetery extends Asset {
    protected static CemeteryDelegate delegate;
    protected double totalArea;
    protected int totalPlots;
    protected int availablePlots;
    protected boolean hasChapel;



    public double getTotalArea() {
        return this.totalArea;
    }

    public void setTotalArea(double totalArea) {
        this.totalArea = totalArea;
    }

    public int getTotalPlots() {
        return this.totalPlots;
    }

    public void setTotalPlots(int totalPlots) {
        this.totalPlots = totalPlots;
    }

    public int getAvailablePlots() {
        return this.availablePlots;
    }

    public void setAvailablePlots(int availablePlots) {
        this.availablePlots = availablePlots;
    }

    public boolean getHasChapel() {
        return this.hasChapel;
    }

    public void setHasChapel(boolean hasChapel) {
        this.hasChapel = hasChapel;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Cemetery entity = (Cemetery) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}