package de.smart.city.culture;
import java.util.Objects;

/**
 **/
public class TicketInfo {
    protected static TicketInfoDelegate delegate;
    protected double basePrice;
    protected double discount;
    protected int availableSeats;
    protected boolean isRefundable;

    public double calculateFinalPrice(){
        return delegate.calculateFinalPrice(this);
    }

    public double getBasePrice() {
        return this.basePrice;
    }

    public void setBasePrice(double basePrice) {
        this.basePrice = basePrice;
    }
    public double getDiscount() {
        return this.discount;
    }

    public void setDiscount(double discount) {
        this.discount = discount;
    }

    public int getAvailableSeats() {
        return this.availableSeats;
    }

    public void setAvailableSeats(int availableSeats) {
        this.availableSeats = availableSeats;
    }

    public boolean getIsRefundable() {
        return this.isRefundable;
    }

    public void setIsRefundable(boolean isRefundable) {
        this.isRefundable = isRefundable;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TicketInfo entity = (TicketInfo) o;
        return Objects.equals(basePrice, entity.basePrice)  && Objects.equals(discount, entity.discount)  && Objects.equals(availableSeats, entity.availableSeats)  && Objects.equals(isRefundable, entity.isRefundable) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(basePrice, discount, availableSeats, isRefundable);
    }
}