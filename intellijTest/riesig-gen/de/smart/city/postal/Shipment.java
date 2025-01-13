package de.smart.city.postal;

import java.time.LocalDateTime;
import java.util.Objects;

public class Shipment {
    protected static ShipmentDelegate delegate;
    protected String trackingId;
    protected MailType type;
    protected DeliveryStatus status;
    protected LocalDateTime receivedTime;
    protected LocalDateTime estimatedDelivery;
    protected boolean isInsured;



    public String getTrackingId() {
        return this.trackingId;
    }

    public void setTrackingId(String trackingId) {
        this.trackingId = trackingId;
    }

    public MailType getType() {
        return this.type;
    }

    public void setType(MailType type) {
        this.type = type;
    }

    public DeliveryStatus getStatus() {
        return this.status;
    }

    public void setStatus(DeliveryStatus status) {
        this.status = status;
    }

    public LocalDateTime getReceivedTime() {
        return this.receivedTime;
    }

    public void setReceivedTime(LocalDateTime receivedTime) {
        this.receivedTime = receivedTime;
    }

    public LocalDateTime getEstimatedDelivery() {
        return this.estimatedDelivery;
    }

    public void setEstimatedDelivery(LocalDateTime estimatedDelivery) {
        this.estimatedDelivery = estimatedDelivery;
    }

    public boolean getIsInsured() {
        return this.isInsured;
    }

    public void setIsInsured(boolean isInsured) {
        this.isInsured = isInsured;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Shipment entity = (Shipment) o;
        return Objects.equals(trackingId, entity.trackingId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(trackingId);
    }
}