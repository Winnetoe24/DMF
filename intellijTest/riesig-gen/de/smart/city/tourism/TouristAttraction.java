package de.smart.city.tourism;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class TouristAttraction extends Asset {
    protected static TouristAttractionDelegate delegate;
    protected AttractionType type;
    protected int dailyVisitorCapacity;
    protected double entryFee;
    protected boolean isAccessible;



    public AttractionType getType() {
        return this.type;
    }

    public void setType(AttractionType type) {
        this.type = type;
    }

    public int getDailyVisitorCapacity() {
        return this.dailyVisitorCapacity;
    }

    public void setDailyVisitorCapacity(int dailyVisitorCapacity) {
        this.dailyVisitorCapacity = dailyVisitorCapacity;
    }

    public double getEntryFee() {
        return this.entryFee;
    }

    public void setEntryFee(double entryFee) {
        this.entryFee = entryFee;
    }

    public boolean getIsAccessible() {
        return this.isAccessible;
    }

    public void setIsAccessible(boolean isAccessible) {
        this.isAccessible = isAccessible;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TouristAttraction entity = (TouristAttraction) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}