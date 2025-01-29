package de.smart.city.library;
import java.util.Objects;

/**
 **/
public class LoanPolicy {
    protected static LoanPolicyDelegate delegate;
    protected int maxRenewals;
    protected double lateFeePerDay;
    protected int gracePeriod;
    protected boolean allowsReservation;

    public double calculateLateFee(int daysOverdue){
        return delegate.calculateLateFee(this, daysOverdue);
    }

    public int getMaxRenewals() {
        return this.maxRenewals;
    }

    public void setMaxRenewals(int maxRenewals) {
        this.maxRenewals = maxRenewals;
    }
    public double getLateFeePerDay() {
        return this.lateFeePerDay;
    }

    public void setLateFeePerDay(double lateFeePerDay) {
        this.lateFeePerDay = lateFeePerDay;
    }

    public int getGracePeriod() {
        return this.gracePeriod;
    }

    public void setGracePeriod(int gracePeriod) {
        this.gracePeriod = gracePeriod;
    }

    public boolean getAllowsReservation() {
        return this.allowsReservation;
    }

    public void setAllowsReservation(boolean allowsReservation) {
        this.allowsReservation = allowsReservation;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LoanPolicy entity = (LoanPolicy) o;
        return Objects.equals(maxRenewals, entity.maxRenewals)  && Objects.equals(lateFeePerDay, entity.lateFeePerDay)  && Objects.equals(gracePeriod, entity.gracePeriod)  && Objects.equals(allowsReservation, entity.allowsReservation) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(maxRenewals, lateFeePerDay, gracePeriod, allowsReservation);
    }
}