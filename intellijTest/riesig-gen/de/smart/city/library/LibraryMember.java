package de.smart.city.library;

import java.time.LocalDate;
import java.util.Objects;

public class LibraryMember {
    protected static LibraryMemberDelegate delegate;
    protected String memberId;
    protected MembershipLevel level;
    protected String name;
    protected String email;
    protected LocalDate joinDate;
    protected LocalDate membershipExpiry;
    protected boolean isActive;
    protected int currentBorrows;



    public String getMemberId() {
        return this.memberId;
    }

    public void setMemberId(String memberId) {
        this.memberId = memberId;
    }

    public MembershipLevel getLevel() {
        return this.level;
    }

    public void setLevel(MembershipLevel level) {
        this.level = level;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public LocalDate getJoinDate() {
        return this.joinDate;
    }

    public void setJoinDate(LocalDate joinDate) {
        this.joinDate = joinDate;
    }

    public LocalDate getMembershipExpiry() {
        return this.membershipExpiry;
    }

    public void setMembershipExpiry(LocalDate membershipExpiry) {
        this.membershipExpiry = membershipExpiry;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }

    public int getCurrentBorrows() {
        return this.currentBorrows;
    }

    public void setCurrentBorrows(int currentBorrows) {
        this.currentBorrows = currentBorrows;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LibraryMember entity = (LibraryMember) o;
        return Objects.equals(memberId, entity.memberId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(memberId);
    }
}