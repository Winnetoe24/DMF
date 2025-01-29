package de.smart.city.restaurants;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Restaurant extends Asset {
    protected static RestaurantDelegate delegate;
    protected CuisineType type;
    protected FoodSafetyRating rating;
    protected int seatingCapacity;
    protected boolean hasDelivery;



    public CuisineType getType() {
        return this.type;
    }

    public void setType(CuisineType type) {
        this.type = type;
    }

    public FoodSafetyRating getRating() {
        return this.rating;
    }

    public void setRating(FoodSafetyRating rating) {
        this.rating = rating;
    }

    public int getSeatingCapacity() {
        return this.seatingCapacity;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    public boolean getHasDelivery() {
        return this.hasDelivery;
    }

    public void setHasDelivery(boolean hasDelivery) {
        this.hasDelivery = hasDelivery;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Restaurant entity = (Restaurant) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}