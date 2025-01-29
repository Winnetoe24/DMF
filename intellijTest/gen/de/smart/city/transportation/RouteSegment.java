package de.smart.city.transportation;

import de.smart.city.infrastructure.GeoLocation;
import java.util.Objects;

/**
 **/
public class RouteSegment {
    protected static RouteSegmentDelegate delegate;
    protected GeoLocation startPoint;
    protected GeoLocation endPoint;
    protected double distance;
    protected int estimatedTimeMinutes;

    public double calculateCongestion(){
        return delegate.calculateCongestion(this);
    }

    public GeoLocation getStartPoint() {
        return this.startPoint;
    }

    public void setStartPoint(GeoLocation startPoint) {
        this.startPoint = startPoint;
    }
    public GeoLocation getEndPoint() {
        return this.endPoint;
    }

    public void setEndPoint(GeoLocation endPoint) {
        this.endPoint = endPoint;
    }

    public double getDistance() {
        return this.distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }

    public int getEstimatedTimeMinutes() {
        return this.estimatedTimeMinutes;
    }

    public void setEstimatedTimeMinutes(int estimatedTimeMinutes) {
        this.estimatedTimeMinutes = estimatedTimeMinutes;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RouteSegment entity = (RouteSegment) o;
        return Objects.equals(estimatedTimeMinutes, entity.estimatedTimeMinutes)  && Objects.equals(startPoint, entity.startPoint)  && Objects.equals(endPoint, entity.endPoint)  && Objects.equals(distance, entity.distance) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(estimatedTimeMinutes, startPoint, endPoint, distance);
    }
}