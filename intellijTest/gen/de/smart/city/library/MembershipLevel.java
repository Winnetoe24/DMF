package de.smart.city.library;

/**
 **/
public enum MembershipLevel {
    BASIC(3, 14),
    STANDARD(5, 21),
    PREMIUM(10, 30),
    RESEARCHER(15, 45),
    INSTITUTIONAL(20, 60);

    protected int maxBorrows;
    protected int durationDays;

    MembershipLevel(int maxBorrows, int durationDays){
        
        this.maxBorrows = maxBorrows;
        this.durationDays = durationDays;
    }
}