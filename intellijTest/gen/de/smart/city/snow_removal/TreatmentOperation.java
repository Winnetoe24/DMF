package de.smart.city.snow_removal;

import java.time.LocalDateTime;
import java.util.Objects;

public class TreatmentOperation {
    protected static TreatmentOperationDelegate delegate;
    protected String operationId;
    protected TreatmentType type;
    protected SnowRoute route;
    protected LocalDateTime startTime;
    protected LocalDateTime completionTime;
    protected double materialUsed;



    public String getOperationId() {
        return this.operationId;
    }

    public void setOperationId(String operationId) {
        this.operationId = operationId;
    }

    public TreatmentType getType() {
        return this.type;
    }

    public void setType(TreatmentType type) {
        this.type = type;
    }

    public SnowRoute getRoute() {
        return this.route;
    }

    public void setRoute(SnowRoute route) {
        this.route = route;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getCompletionTime() {
        return this.completionTime;
    }

    public void setCompletionTime(LocalDateTime completionTime) {
        this.completionTime = completionTime;
    }

    public double getMaterialUsed() {
        return this.materialUsed;
    }

    public void setMaterialUsed(double materialUsed) {
        this.materialUsed = materialUsed;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TreatmentOperation entity = (TreatmentOperation) o;
        return Objects.equals(operationId, entity.operationId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(operationId);
    }
}