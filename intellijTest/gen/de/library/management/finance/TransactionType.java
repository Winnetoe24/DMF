package de.library.management.finance;

/**
 * Transaktionstypen
 **/
public enum TransactionType {
    MEMBERSHIP_FEE("TODO"),
    LATE_FEE("TODO"),
    REPLACEMENT_FEE("TODO"),
    PRINTING_FEE("TODO"),
    DEPOSIT("TODO");

    protected String name;

    TransactionType(String name){
        
        this.name = name;
    }
}