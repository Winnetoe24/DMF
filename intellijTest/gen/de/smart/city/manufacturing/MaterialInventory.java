package de.smart.city.manufacturing;

import java.time.LocalDate;
import java.util.Objects;

public class MaterialInventory {
    protected static MaterialInventoryDelegate delegate;
    protected String inventoryId;
    protected String materialType;
    protected double quantity;
    protected String unit;
    protected LocalDate expiryDate;
    protected String supplier;
    protected String storageLocation;
    protected boolean hazardous;



    public String getInventoryId() {
        return this.inventoryId;
    }

    public void setInventoryId(String inventoryId) {
        this.inventoryId = inventoryId;
    }

    public String getMaterialType() {
        return this.materialType;
    }

    public void setMaterialType(String materialType) {
        this.materialType = materialType;
    }

    public double getQuantity() {
        return this.quantity;
    }

    public void setQuantity(double quantity) {
        this.quantity = quantity;
    }

    public String getUnit() {
        return this.unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public LocalDate getExpiryDate() {
        return this.expiryDate;
    }

    public void setExpiryDate(LocalDate expiryDate) {
        this.expiryDate = expiryDate;
    }

    public String getSupplier() {
        return this.supplier;
    }

    public void setSupplier(String supplier) {
        this.supplier = supplier;
    }

    public String getStorageLocation() {
        return this.storageLocation;
    }

    public void setStorageLocation(String storageLocation) {
        this.storageLocation = storageLocation;
    }

    public boolean getHazardous() {
        return this.hazardous;
    }

    public void setHazardous(boolean hazardous) {
        this.hazardous = hazardous;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MaterialInventory entity = (MaterialInventory) o;
        return Objects.equals(inventoryId, entity.inventoryId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(inventoryId);
    }
}