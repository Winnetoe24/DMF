package de.library.management.finance;

/**
 * Transaktionstypen
 **/
public enum TransactionType {
    MEMBERSHIP_FEE("Mitgliedsbeitrag"),
    LATE_FEE("Mahngebühr"),
    REPLACEMENT_FEE("Ersatzgebühr"),
    PRINTING_FEE("Druckkosten"),
    DEPOSIT("Kaution");

    protected String name;

    TransactionType(String name){
        
        this.name = name;
    }
}