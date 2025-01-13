package de.smart.city.environment;

import java.time.LocalDate;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class MonitoringStation extends Asset {
    protected static MonitoringStationDelegate delegate;
    protected String stationId;
    protected boolean isCalibrated;
    protected LocalDate lastCalibrationDate;



    public String getStationId() {
        return this.stationId;
    }

    public void setStationId(String stationId) {
        this.stationId = stationId;
    }

    public boolean getIsCalibrated() {
        return this.isCalibrated;
    }

    public void setIsCalibrated(boolean isCalibrated) {
        this.isCalibrated = isCalibrated;
    }

    public LocalDate getLastCalibrationDate() {
        return this.lastCalibrationDate;
    }

    public void setLastCalibrationDate(LocalDate lastCalibrationDate) {
        this.lastCalibrationDate = lastCalibrationDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MonitoringStation entity = (MonitoringStation) o;
        return Objects.equals(stationId, entity.stationId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(stationId);
    }
}