package de.smart.city.energy;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class PowerPlant extends Asset {
    protected static PowerPlantDelegate delegate;
    protected EnergySource source;
    protected double capacity;
    protected double currentOutput;
    protected double efficiency;
    protected boolean isBackupSource;



    public EnergySource getSource() {
        return this.source;
    }

    public void setSource(EnergySource source) {
        this.source = source;
    }

    public double getCapacity() {
        return this.capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public double getCurrentOutput() {
        return this.currentOutput;
    }

    public void setCurrentOutput(double currentOutput) {
        this.currentOutput = currentOutput;
    }

    public double getEfficiency() {
        return this.efficiency;
    }

    public void setEfficiency(double efficiency) {
        this.efficiency = efficiency;
    }

    public boolean getIsBackupSource() {
        return this.isBackupSource;
    }

    public void setIsBackupSource(boolean isBackupSource) {
        this.isBackupSource = isBackupSource;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PowerPlant entity = (PowerPlant) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}