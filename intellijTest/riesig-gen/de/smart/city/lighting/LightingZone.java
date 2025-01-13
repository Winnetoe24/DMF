package de.smart.city.lighting;
import java.util.Objects;

public class LightingZone {
    protected static LightingZoneDelegate delegate;
    protected String zoneId;
    protected String schedule;
    protected boolean isDimmed;
    protected double dailyUsage;



    public String getZoneId() {
        return this.zoneId;
    }

    public void setZoneId(String zoneId) {
        this.zoneId = zoneId;
    }

    public String getSchedule() {
        return this.schedule;
    }

    public void setSchedule(String schedule) {
        this.schedule = schedule;
    }

    public boolean getIsDimmed() {
        return this.isDimmed;
    }

    public void setIsDimmed(boolean isDimmed) {
        this.isDimmed = isDimmed;
    }

    public double getDailyUsage() {
        return this.dailyUsage;
    }

    public void setDailyUsage(double dailyUsage) {
        this.dailyUsage = dailyUsage;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LightingZone entity = (LightingZone) o;
        return Objects.equals(zoneId, entity.zoneId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(zoneId);
    }
}