package de.smart.city.smartgrid;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class GridNode extends Asset {
    protected static GridNodeDelegate delegate;
    protected GridComponent type;
    protected double voltage;
    protected double current;
    protected LoadProfile profile;
    protected boolean isRedundant;



    public GridComponent getType() {
        return this.type;
    }

    public void setType(GridComponent type) {
        this.type = type;
    }

    public double getVoltage() {
        return this.voltage;
    }

    public void setVoltage(double voltage) {
        this.voltage = voltage;
    }

    public double getCurrent() {
        return this.current;
    }

    public void setCurrent(double current) {
        this.current = current;
    }

    public LoadProfile getProfile() {
        return this.profile;
    }

    public void setProfile(LoadProfile profile) {
        this.profile = profile;
    }

    public boolean getIsRedundant() {
        return this.isRedundant;
    }

    public void setIsRedundant(boolean isRedundant) {
        this.isRedundant = isRedundant;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        GridNode entity = (GridNode) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}