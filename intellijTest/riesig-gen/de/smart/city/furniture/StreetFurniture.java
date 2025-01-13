package de.smart.city.furniture;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class StreetFurniture extends Asset {
    protected static StreetFurnitureDelegate delegate;
    protected FurnitureType type;
    protected MaintenanceState state;
    protected String material;
    protected boolean needsRepair;



    public FurnitureType getType() {
        return this.type;
    }

    public void setType(FurnitureType type) {
        this.type = type;
    }

    public MaintenanceState getState() {
        return this.state;
    }

    public void setState(MaintenanceState state) {
        this.state = state;
    }

    public String getMaterial() {
        return this.material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public boolean getNeedsRepair() {
        return this.needsRepair;
    }

    public void setNeedsRepair(boolean needsRepair) {
        this.needsRepair = needsRepair;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        StreetFurniture entity = (StreetFurniture) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}