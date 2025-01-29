package de.smart.city.weather;

import java.time.LocalDateTime;
import java.util.Objects;

public class WeatherAlert {
    protected static WeatherAlertDelegate delegate;
    protected String alertId;
    protected AlertLevel level;
    protected String message;
    protected LocalDateTime issueTime;
    protected LocalDateTime expiryTime;
    protected boolean isActive;



    public String getAlertId() {
        return this.alertId;
    }

    public void setAlertId(String alertId) {
        this.alertId = alertId;
    }

    public AlertLevel getLevel() {
        return this.level;
    }

    public void setLevel(AlertLevel level) {
        this.level = level;
    }

    public String getMessage() {
        return this.message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public LocalDateTime getIssueTime() {
        return this.issueTime;
    }

    public void setIssueTime(LocalDateTime issueTime) {
        this.issueTime = issueTime;
    }

    public LocalDateTime getExpiryTime() {
        return this.expiryTime;
    }

    public void setExpiryTime(LocalDateTime expiryTime) {
        this.expiryTime = expiryTime;
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
        WeatherAlert entity = (WeatherAlert) o;
        return Objects.equals(alertId, entity.alertId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(alertId);
    }
}