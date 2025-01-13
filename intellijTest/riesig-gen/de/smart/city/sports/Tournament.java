package de.smart.city.sports;

import java.time.LocalDate;
import java.util.Objects;

public class Tournament {
    protected static TournamentDelegate delegate;
    protected String tournamentId;
    protected SportType sport;
    protected LocalDate startDate;
    protected LocalDate endDate;
    protected int participants;
    protected String sponsor;



    public String getTournamentId() {
        return this.tournamentId;
    }

    public void setTournamentId(String tournamentId) {
        this.tournamentId = tournamentId;
    }

    public SportType getSport() {
        return this.sport;
    }

    public void setSport(SportType sport) {
        this.sport = sport;
    }

    public LocalDate getStartDate() {
        return this.startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public LocalDate getEndDate() {
        return this.endDate;
    }

    public void setEndDate(LocalDate endDate) {
        this.endDate = endDate;
    }

    public int getParticipants() {
        return this.participants;
    }

    public void setParticipants(int participants) {
        this.participants = participants;
    }

    public String getSponsor() {
        return this.sponsor;
    }

    public void setSponsor(String sponsor) {
        this.sponsor = sponsor;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Tournament entity = (Tournament) o;
        return Objects.equals(tournamentId, entity.tournamentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(tournamentId);
    }
}