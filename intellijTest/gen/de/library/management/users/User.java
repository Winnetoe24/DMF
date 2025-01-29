package de.library.management.users;

import java.time.LocalDate;
import java.util.Objects;

public class User {
    protected static UserDelegate delegate;
    protected String firstName;
    protected String lastName;
    protected LocalDate dateOfBirth;
    protected String email;
    protected Address address;
    protected MembershipType membershipType;
    protected UserStatus status;
    protected LocalDate memberSince;
    protected LocalDate membershipExpiry;



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

    public Address getAddress() {
        return this.address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public MembershipType getMembershipType() {
        return this.membershipType;
    }

    public void setMembershipType(MembershipType membershipType) {
        this.membershipType = membershipType;
    }

    public UserStatus getStatus() {
        return this.status;
    }

    public void setStatus(UserStatus status) {
        this.status = status;
    }

    public LocalDate getMemberSince() {
        return this.memberSince;
    }

    public void setMemberSince(LocalDate memberSince) {
        this.memberSince = memberSince;
    }

    public LocalDate getMembershipExpiry() {
        return this.membershipExpiry;
    }

    public void setMembershipExpiry(LocalDate membershipExpiry) {
        this.membershipExpiry = membershipExpiry;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        User entity = (User) o;
        return Objects.equals(email, entity.email) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(email);
    }
}