package de.smart.city.postal;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class PostOffice extends Asset {
    protected static PostOfficeDelegate delegate;
    protected int counterCount;
    protected int staffCount;
    protected boolean hasAutomation;
    protected double storageCapacity;



    public int getCounterCount() {
        return this.counterCount;
    }

    public void setCounterCount(int counterCount) {
        this.counterCount = counterCount;
    }

    public int getStaffCount() {
        return this.staffCount;
    }

    public void setStaffCount(int staffCount) {
        this.staffCount = staffCount;
    }

    public boolean getHasAutomation() {
        return this.hasAutomation;
    }

    public void setHasAutomation(boolean hasAutomation) {
        this.hasAutomation = hasAutomation;
    }

    public double getStorageCapacity() {
        return this.storageCapacity;
    }

    public void setStorageCapacity(double storageCapacity) {
        this.storageCapacity = storageCapacity;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PostOffice entity = (PostOffice) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}