package de.smart.city.parking;

import java.time.LocalDateTime;
import java.util.Objects;

public class ParkingTransaction {
    protected static ParkingTransactionDelegate delegate;
    protected String transactionId;
    protected VehicleSize vehicleSize;
    protected LocalDateTime entryTime;
    protected LocalDateTime exitTime;
    protected double amount;
    protected boolean isPaid;



    public String getTransactionId() {
        return this.transactionId;
    }

    public void setTransactionId(String transactionId) {
        this.transactionId = transactionId;
    }

    public VehicleSize getVehicleSize() {
        return this.vehicleSize;
    }

    public void setVehicleSize(VehicleSize vehicleSize) {
        this.vehicleSize = vehicleSize;
    }

    public LocalDateTime getEntryTime() {
        return this.entryTime;
    }

    public void setEntryTime(LocalDateTime entryTime) {
        this.entryTime = entryTime;
    }

    public LocalDateTime getExitTime() {
        return this.exitTime;
    }

    public void setExitTime(LocalDateTime exitTime) {
        this.exitTime = exitTime;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public boolean getIsPaid() {
        return this.isPaid;
    }

    public void setIsPaid(boolean isPaid) {
        this.isPaid = isPaid;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ParkingTransaction entity = (ParkingTransaction) o;
        return Objects.equals(transactionId, entity.transactionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(transactionId);
    }
}