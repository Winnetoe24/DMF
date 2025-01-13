package de.smart.city.snow_removal;

import java.time.LocalDateTime;
import java.util.Objects;

public class SnowRoute {
    protected static SnowRouteDelegate delegate;
    protected String routeId;
    protected PriorityLevel priority;
    protected double length;
    protected int estimatedTime;
    protected boolean isCleared;
    protected LocalDateTime lastCleared;



    public String getRouteId() {
        return this.routeId;
    }

    public void setRouteId(String routeId) {
        this.routeId = routeId;
    }

    public PriorityLevel getPriority() {
        return this.priority;
    }

    public void setPriority(PriorityLevel priority) {
        this.priority = priority;
    }

    public double getLength() {
        return this.length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public int getEstimatedTime() {
        return this.estimatedTime;
    }

    public void setEstimatedTime(int estimatedTime) {
        this.estimatedTime = estimatedTime;
    }

    public boolean getIsCleared() {
        return this.isCleared;
    }

    public void setIsCleared(boolean isCleared) {
        this.isCleared = isCleared;
    }

    public LocalDateTime getLastCleared() {
        return this.lastCleared;
    }

    public void setLastCleared(LocalDateTime lastCleared) {
        this.lastCleared = lastCleared;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SnowRoute entity = (SnowRoute) o;
        return Objects.equals(routeId, entity.routeId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(routeId);
    }
}