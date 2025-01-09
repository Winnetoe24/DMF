package de.library.management.employees;

/**
 * Abteilungen
 **/
public enum Department {
    ADMINISTRATION("Verwaltung"),
    CATALOGING("Katalogisierung"),
    USER_SERVICES("Benutzerdienste"),
    IT_SUPPORT("IT-Support"),
    FACILITY_MANAGEMENT("Gebäudemanagement");

    protected String name;

    Department(String name){
        
        this.name = name;
    }
}