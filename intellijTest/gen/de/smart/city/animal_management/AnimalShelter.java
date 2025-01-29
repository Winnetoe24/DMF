package de.smart.city.animal_management;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class AnimalShelter extends Asset {
    protected static AnimalShelterDelegate delegate;
    protected String shelterName;
    protected int capacity;
    protected int currentOccupancy;
    protected boolean acceptsStrays;
    protected boolean providesVetCare;



    public String getShelterName() {
        return this.shelterName;
    }

    public void setShelterName(String shelterName) {
        this.shelterName = shelterName;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCurrentOccupancy() {
        return this.currentOccupancy;
    }

    public void setCurrentOccupancy(int currentOccupancy) {
        this.currentOccupancy = currentOccupancy;
    }

    public boolean getAcceptsStrays() {
        return this.acceptsStrays;
    }

    public void setAcceptsStrays(boolean acceptsStrays) {
        this.acceptsStrays = acceptsStrays;
    }

    public boolean getProvidesVetCare() {
        return this.providesVetCare;
    }

    public void setProvidesVetCare(boolean providesVetCare) {
        this.providesVetCare = providesVetCare;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AnimalShelter entity = (AnimalShelter) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}