package de.smart.city.media_production;

import java.time.LocalDateTime;
import java.util.Objects;

public class FilmPermit {
    protected static FilmPermitDelegate delegate;
    protected String permitId;
    protected ProductionType type;
    protected PermitStatus status;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String location;
    protected int crewSize;



    public String getPermitId() {
        return this.permitId;
    }

    public void setPermitId(String permitId) {
        this.permitId = permitId;
    }

    public ProductionType getType() {
        return this.type;
    }

    public void setType(ProductionType type) {
        this.type = type;
    }

    public PermitStatus getStatus() {
        return this.status;
    }

    public void setStatus(PermitStatus status) {
        this.status = status;
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

    public String getLocation() {
        return this.location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public int getCrewSize() {
        return this.crewSize;
    }

    public void setCrewSize(int crewSize) {
        this.crewSize = crewSize;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        FilmPermit entity = (FilmPermit) o;
        return Objects.equals(permitId, entity.permitId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(permitId);
    }
}