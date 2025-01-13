package de.smart.city.culture;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class CulturalVenue extends Asset {
    protected static CulturalVenueDelegate delegate;
    protected VenueType type;
    protected int capacity;
    protected boolean hasAccessibility;



    public VenueType getType() {
        return this.type;
    }

    public void setType(VenueType type) {
        this.type = type;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public boolean getHasAccessibility() {
        return this.hasAccessibility;
    }

    public void setHasAccessibility(boolean hasAccessibility) {
        this.hasAccessibility = hasAccessibility;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        CulturalVenue entity = (CulturalVenue) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}