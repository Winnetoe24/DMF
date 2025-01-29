package de.smart.city.transit_payment;

import java.time.LocalDateTime;
import java.util.Objects;

public class FareTransaction {
    protected static FareTransactionDelegate delegate;
    protected String transactionId;
    protected TransitCard card;
    protected LocalDateTime timestamp;
    protected double amount;
    protected String route;
    protected boolean isRefunded;



    public String getTransactionId() {
        return this.transactionId;
    }

    public void setTransactionId(String transactionId) {
        this.transactionId = transactionId;
    }

    public TransitCard getCard() {
        return this.card;
    }

    public void setCard(TransitCard card) {
        this.card = card;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getRoute() {
        return this.route;
    }

    public void setRoute(String route) {
        this.route = route;
    }

    public boolean getIsRefunded() {
        return this.isRefunded;
    }

    public void setIsRefunded(boolean isRefunded) {
        this.isRefunded = isRefunded;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FareTransaction entity = (FareTransaction) o;
        return Objects.equals(transactionId, entity.transactionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(transactionId);
    }
}