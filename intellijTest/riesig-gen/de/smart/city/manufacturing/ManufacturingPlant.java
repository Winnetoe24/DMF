package de.smart.city.manufacturing;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class ManufacturingPlant extends Asset {
    protected static ManufacturingPlantDelegate delegate;
    protected int employeeCount;
    protected double productionCapacity;
    protected boolean isTwentyFourSeven;
    protected double totalArea;
    protected int shiftCount;



    public int getEmployeeCount() {
        return this.employeeCount;
    }

    public void setEmployeeCount(int employeeCount) {
        this.employeeCount = employeeCount;
    }

    public double getProductionCapacity() {
        return this.productionCapacity;
    }

    public void setProductionCapacity(double productionCapacity) {
        this.productionCapacity = productionCapacity;
    }

    public boolean getIsTwentyFourSeven() {
        return this.isTwentyFourSeven;
    }

    public void setIsTwentyFourSeven(boolean isTwentyFourSeven) {
        this.isTwentyFourSeven = isTwentyFourSeven;
    }

    public double getTotalArea() {
        return this.totalArea;
    }

    public void setTotalArea(double totalArea) {
        this.totalArea = totalArea;
    }

    public int getShiftCount() {
        return this.shiftCount;
    }

    public void setShiftCount(int shiftCount) {
        this.shiftCount = shiftCount;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ManufacturingPlant entity = (ManufacturingPlant) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}