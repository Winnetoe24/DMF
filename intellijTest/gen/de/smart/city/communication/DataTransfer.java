package de.smart.city.communication;

import java.time.LocalDateTime;
import java.util.Objects;

public class DataTransfer {
    protected static DataTransferDelegate delegate;
    protected String transferId;
    protected NetworkNode source;
    protected NetworkNode destination;
    protected double amount;
    protected LocalDateTime timestamp;
    protected boolean isEncrypted;



    public String getTransferId() {
        return this.transferId;
    }

    public void setTransferId(String transferId) {
        this.transferId = transferId;
    }

    public NetworkNode getSource() {
        return this.source;
    }

    public void setSource(NetworkNode source) {
        this.source = source;
    }

    public NetworkNode getDestination() {
        return this.destination;
    }

    public void setDestination(NetworkNode destination) {
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

    public boolean getIsEncrypted() {
        return this.isEncrypted;
    }

    public void setIsEncrypted(boolean isEncrypted) {
        this.isEncrypted = isEncrypted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        DataTransfer entity = (DataTransfer) o;
        return Objects.equals(transferId, entity.transferId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(transferId);
    }
}