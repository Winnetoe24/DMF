package de.smart.city.emergency;

import de.smart.city.infrastructure.GeoLocation;
import java.util.Objects;

public class EmergencyTeam {
    protected static EmergencyTeamDelegate delegate;
    protected String teamId;
    protected EmergencyType specialty;
    protected int memberCount;
    protected GeoLocation currentLocation;
    protected boolean isAvailable;



    public String getTeamId() {
        return this.teamId;
    }

    public void setTeamId(String teamId) {
        this.teamId = teamId;
    }

    public EmergencyType getSpecialty() {
        return this.specialty;
    }

    public void setSpecialty(EmergencyType specialty) {
        this.specialty = specialty;
    }

    public int getMemberCount() {
        return this.memberCount;
    }

    public void setMemberCount(int memberCount) {
        this.memberCount = memberCount;
    }

    public GeoLocation getCurrentLocation() {
        return this.currentLocation;
    }

    public void setCurrentLocation(GeoLocation currentLocation) {
        this.currentLocation = currentLocation;
    }

    public boolean getIsAvailable() {
        return this.isAvailable;
    }

    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EmergencyTeam entity = (EmergencyTeam) o;
        return Objects.equals(teamId, entity.teamId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(teamId);
    }
}