package de.smart.city.drones;

import java.time.LocalDateTime;
import java.util.Objects;

public class FlightMission {
    protected static FlightMissionDelegate delegate;
    protected String missionId;
    protected Drone drone;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String purpose;
    protected boolean isCompleted;



    public String getMissionId() {
        return this.missionId;
    }

    public void setMissionId(String missionId) {
        this.missionId = missionId;
    }

    public Drone getDrone() {
        return this.drone;
    }

    public void setDrone(Drone drone) {
        this.drone = drone;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getEndTime() {
        return this.endTime;
    }

    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    public String getPurpose() {
        return this.purpose;
    }

    public void setPurpose(String purpose) {
        this.purpose = purpose;
    }

    public boolean getIsCompleted() {
        return this.isCompleted;
    }

    public void setIsCompleted(boolean isCompleted) {
        this.isCompleted = isCompleted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FlightMission entity = (FlightMission) o;
        return Objects.equals(missionId, entity.missionId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(missionId);
    }
}