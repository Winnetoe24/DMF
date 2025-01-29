package de.smart.city.citizens;

import java.time.LocalDate;
import de.smart.city.infrastructure.GeoLocation;
import java.util.Objects;

public class Citizen {
    protected static CitizenDelegate delegate;
    protected String citizenId;
    protected String firstName;
    protected String lastName;
    protected GeoLocation residence;
    protected LocalDate dateOfBirth;
    protected String email;
    protected String phone;



    public String getCitizenId() {
        return this.citizenId;
    }

    public void setCitizenId(String citizenId) {
        this.citizenId = citizenId;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public GeoLocation getResidence() {
        return this.residence;
    }

    public void setResidence(GeoLocation residence) {
        this.residence = residence;
    }

    public LocalDate getDateOfBirth() {
        return this.dateOfBirth;
    }

    public void setDateOfBirth(LocalDate dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return this.phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Citizen entity = (Citizen) o;
        return Objects.equals(citizenId, entity.citizenId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(citizenId);
    }
}