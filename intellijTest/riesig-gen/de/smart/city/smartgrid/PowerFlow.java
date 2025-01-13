package de.smart.city.smartgrid;

import java.time.LocalDateTime;
import java.util.Objects;

public class PowerFlow {
    protected static PowerFlowDelegate delegate;
    protected String flowId;
    protected GridNode source;
    protected GridNode destination;
    protected double amount;
    protected LocalDateTime timestamp;
    protected boolean isStable;



    public String getFlowId() {
        return this.flowId;
    }

    public void setFlowId(String flowId) {
        this.flowId = flowId;
    }

    public GridNode getSource() {
        return this.source;
    }

    public void setSource(GridNode source) {
        this.source = source;
    }

    public GridNode getDestination() {
        return this.destination;
    }

    public void setDestination(GridNode destination) {
        this.destination = destination;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public boolean getIsStable() {
        return this.isStable;
    }

    public void setIsStable(boolean isStable) {
        this.isStable = isStable;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PowerFlow entity = (PowerFlow) o;
        return Objects.equals(flowId, entity.flowId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(flowId);
    }
}