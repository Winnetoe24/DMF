package de.smart.city.buildings;

import java.time.LocalDateTime;
import java.util.Objects;

public class SmartDevice {
    protected static SmartDeviceDelegate delegate;
    protected String deviceId;
    protected Building building;
    protected String deviceType;
    protected boolean isOnline;
    protected LocalDateTime lastPing;
    protected String firmwareVersion;



    public String getDeviceId() {
        return this.deviceId;
    }

    public void setDeviceId(String deviceId) {
        this.deviceId = deviceId;
    }

    public Building getBuilding() {
        return this.building;
    }

    public void setBuilding(Building building) {
        this.building = building;
    }

    public String getDeviceType() {
        return this.deviceType;
    }

    public void setDeviceType(String deviceType) {
        this.deviceType = deviceType;
    }

    public boolean getIsOnline() {
        return this.isOnline;
    }

    public void setIsOnline(boolean isOnline) {
        this.isOnline = isOnline;
    }

    public LocalDateTime getLastPing() {
        return this.lastPing;
    }

    public void setLastPing(LocalDateTime lastPing) {
        this.lastPing = lastPing;
    }

    public String getFirmwareVersion() {
        return this.firmwareVersion;
    }

    public void setFirmwareVersion(String firmwareVersion) {
        this.firmwareVersion = firmwareVersion;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SmartDevice entity = (SmartDevice) o;
        return Objects.equals(deviceId, entity.deviceId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(deviceId);
    }
}