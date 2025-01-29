package de.smart.city.markets;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Market extends Asset {
    protected static MarketDelegate delegate;
    protected MarketType type;
    protected int stallCapacity;
    protected LocalDateTime openTime;
    protected LocalDateTime closeTime;



    public MarketType getType() {
        return this.type;
    }

    public void setType(MarketType type) {
        this.type = type;
    }

    public int getStallCapacity() {
        return this.stallCapacity;
    }

    public void setStallCapacity(int stallCapacity) {
        this.stallCapacity = stallCapacity;
    }

    public LocalDateTime getOpenTime() {
        return this.openTime;
    }

    public void setOpenTime(LocalDateTime openTime) {
        this.openTime = openTime;
    }

    public LocalDateTime getCloseTime() {
        return this.closeTime;
    }

    public void setCloseTime(LocalDateTime closeTime) {
        this.closeTime = closeTime;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Market entity = (Market) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}