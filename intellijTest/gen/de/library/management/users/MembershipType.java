package de.library.management.users;

import java.time.LocalDate;

/**
 * Verschiedene Mitgliedsarten
 **/
public enum MembershipType {
    STANDARD(10, java.time.LocalDate.of(2024, 1, 1)),
    PREMIUM(20, java.time.LocalDate.of(2024, 1, 1)),
    STUDENT(15, java.time.LocalDate.of(2024, 1, 1));

    protected int preis;
    protected LocalDate startdatum;

    MembershipType(int preis, LocalDate startdatum){
        
        this.preis = preis;
        this.startdatum = startdatum;
    }
}