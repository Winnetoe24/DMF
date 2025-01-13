package de.smart.city.manufacturing;

import java.time.LocalDateTime;
import java.util.Objects;

public class ProductionLine {
    protected static ProductionLineDelegate delegate;
    protected String lineId;
    protected ProductionLineType type;
    protected MachineStatus status;
    protected ProductionMetrics metrics;
    protected int workerCount;
    protected double outputRate;
    protected String currentProduct;
    protected LocalDateTime lastStartup;



    public String getLineId() {
        return this.lineId;
    }

    public void setLineId(String lineId) {
        this.lineId = lineId;
    }

    public ProductionLineType getType() {
        return this.type;
    }

    public void setType(ProductionLineType type) {
        this.type = type;
    }

    public MachineStatus getStatus() {
        return this.status;
    }

    public void setStatus(MachineStatus status) {
        this.status = status;
    }

    public ProductionMetrics getMetrics() {
        return this.metrics;
    }

    public void setMetrics(ProductionMetrics metrics) {
        this.metrics = metrics;
    }

    public int getWorkerCount() {
        return this.workerCount;
    }

    public void setWorkerCount(int workerCount) {
        this.workerCount = workerCount;
    }

    public double getOutputRate() {
        return this.outputRate;
    }

    public void setOutputRate(double outputRate) {
        this.outputRate = outputRate;
    }

    public String getCurrentProduct() {
        return this.currentProduct;
    }

    public void setCurrentProduct(String currentProduct) {
        this.currentProduct = currentProduct;
    }

    public LocalDateTime getLastStartup() {
        return this.lastStartup;
    }

    public void setLastStartup(LocalDateTime lastStartup) {
        this.lastStartup = lastStartup;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ProductionLine entity = (ProductionLine) o;
        return Objects.equals(lineId, entity.lineId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(lineId);
    }
}