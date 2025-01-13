package de.smart.city.manufacturing;
import java.util.Objects;

/**
 **/
public class ProductionMetrics {
    protected static ProductionMetricsDelegate delegate;
    protected int targetOutput;
    protected int actualOutput;
    protected double efficiency;
    protected int defectRate;
    protected double energyConsumption;
    protected double materialWaste;

    public double calculateOEE(){
        return delegate.calculateOEE(this);
    }

    public boolean isOnTarget(){
        return delegate.isOnTarget(this);
    }

    public double getVariance(){
        return delegate.getVariance(this);
    }

    public int getTargetOutput() {
        return this.targetOutput;
    }

    public void setTargetOutput(int targetOutput) {
        this.targetOutput = targetOutput;
    }

    public int getActualOutput() {
        return this.actualOutput;
    }

    public void setActualOutput(int actualOutput) {
        this.actualOutput = actualOutput;
    }

    public double getEfficiency() {
        return this.efficiency;
    }

    public void setEfficiency(double efficiency) {
        this.efficiency = efficiency;
    }
    public int getDefectRate() {
        return this.defectRate;
    }

    public void setDefectRate(int defectRate) {
        this.defectRate = defectRate;
    }

    public double getEnergyConsumption() {
        return this.energyConsumption;
    }

    public void setEnergyConsumption(double energyConsumption) {
        this.energyConsumption = energyConsumption;
    }

    public double getMaterialWaste() {
        return this.materialWaste;
    }

    public void setMaterialWaste(double materialWaste) {
        this.materialWaste = materialWaste;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ProductionMetrics entity = (ProductionMetrics) o;
        return Objects.equals(actualOutput, entity.actualOutput)  && Objects.equals(targetOutput, entity.targetOutput)  && Objects.equals(efficiency, entity.efficiency)  && Objects.equals(defectRate, entity.defectRate)  && Objects.equals(energyConsumption, entity.energyConsumption)  && Objects.equals(materialWaste, entity.materialWaste) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(actualOutput, targetOutput, efficiency, defectRate, energyConsumption, materialWaste);
    }
}