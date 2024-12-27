package de.library.management.users;

import java.time.LocalDate;
import java.util.Objects;

public class User {
    protected String firstName;
    protected String lastName;
    protected LocalDate dateOfBirth;
    protected String email;
    protected Address address;
    protected MembershipType membershipType;
    protected UserStatus status;
    protected LocalDate memberSince;
    protected LocalDate membershipExpiry;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        User entity = (User) o;
        return Objects.equals(firstName, entity.firstName)  && Objects.equals(lastName, entity.lastName)  && Objects.equals(dateOfBirth, entity.dateOfBirth)  && Objects.equals(email, entity.email)  && Objects.equals(address, entity.address)  && Objects.equals(membershipType, entity.membershipType)  && Objects.equals(status, entity.status)  && Objects.equals(memberSince, entity.memberSince)  && Objects.equals(membershipExpiry, entity.membershipExpiry) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(firstName, lastName, dateOfBirth, email, address, membershipType, status, memberSince, membershipExpiry);
    }
}