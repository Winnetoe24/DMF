package de.smart.city.transit_payment;

import java.time.LocalDate;
import java.util.Objects;

public class TransitCard {
    protected static TransitCardDelegate delegate;
    protected String cardId;
    protected PaymentMethod method;
    protected FareType fareType;
    protected double balance;
    protected LocalDate expiryDate;
    protected boolean isActive;



    public String getCardId() {
        return this.cardId;
    }

    public void setCardId(String cardId) {
        this.cardId = cardId;
    }

    public PaymentMethod getMethod() {
        return this.method;
    }

    public void setMethod(PaymentMethod method) {
        this.method = method;
    }

    public FareType getFareType() {
        return this.fareType;
    }

    public void setFareType(FareType fareType) {
        this.fareType = fareType;
    }

    public double getBalance() {
        return this.balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public LocalDate getExpiryDate() {
        return this.expiryDate;
    }

    public void setExpiryDate(LocalDate expiryDate) {
        this.expiryDate = expiryDate;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TransitCard entity = (TransitCard) o;
        return Objects.equals(cardId, entity.cardId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(cardId);
    }
}