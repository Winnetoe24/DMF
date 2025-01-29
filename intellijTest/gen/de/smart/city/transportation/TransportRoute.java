package de.smart.city.transportation;

import java.time.LocalDateTime;
import java.util.Objects;

public class TransportRoute {
    protected static TransportRouteDelegate delegate;
    protected String routeId;
    protected String routeName;
    protected RouteStatus status;
    protected LocalDateTime firstDepartureTime;
    protected LocalDateTime lastDepartureTime;
    protected int frequencyMinutes;



    public String getRouteId() {
        return this.routeId;
    }

    public void setRouteId(String routeId) {
        this.routeId = routeId;
    }

    public String getRouteName() {
        return this.routeName;
    }

    public void setRouteName(String routeName) {
        this.routeName = routeName;
    }

    public RouteStatus getStatus() {
        return this.status;
    }

    public void setStatus(RouteStatus status) {
        this.status = status;
    }

    public LocalDateTime getFirstDepartureTime() {
        return this.firstDepartureTime;
    }

    public void setFirstDepartureTime(LocalDateTime firstDepartureTime) {
        this.firstDepartureTime = firstDepartureTime;
    }

    public LocalDateTime getLastDepartureTime() {
        return this.lastDepartureTime;
    }

    public void setLastDepartureTime(LocalDateTime lastDepartureTime) {
        this.lastDepartureTime = lastDepartureTime;
    }

    public int getFrequencyMinutes() {
        return this.frequencyMinutes;
    }

    public void setFrequencyMinutes(int frequencyMinutes) {
        this.frequencyMinutes = frequencyMinutes;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TransportRoute entity = (TransportRoute) o;
        return Objects.equals(routeId, entity.routeId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(routeId);
    }
}