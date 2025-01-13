package de.smart.city.retail;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class RetailStore extends Asset {
    protected static RetailStoreDelegate delegate;
    protected StoreType type;
    protected CustomerSegment segment;
    protected double floorArea;
    protected int employeeCount;
    protected boolean isChainStore;



    public StoreType getType() {
        return this.type;
    }

    public void setType(StoreType type) {
        this.type = type;
    }

    public CustomerSegment getSegment() {
        return this.segment;
    }

    public void setSegment(CustomerSegment segment) {
        this.segment = segment;
    }

    public double getFloorArea() {
        return this.floorArea;
    }

    public void setFloorArea(double floorArea) {
        this.floorArea = floorArea;
    }

    public int getEmployeeCount() {
        return this.employeeCount;
    }

    public void setEmployeeCount(int employeeCount) {
        this.employeeCount = employeeCount;
    }

    public boolean getIsChainStore() {
        return this.isChainStore;
    }

    public void setIsChainStore(boolean isChainStore) {
        this.isChainStore = isChainStore;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RetailStore entity = (RetailStore) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}