package de.library.management.lending;

/**
 * Status einer Ausleihe
 **/
public enum LendingStatus {
    BORROWED(),
    RETURNED(),
    OVERDUE(),
    LOST();


    LendingStatus(){
        
    }
}