package de.library.management.media;

/**
 * Kategorisierung der Medien
 **/
public enum Category {
    FICTION("Belletristik"),
    NON_FICTION("Sachbuch"),
    CHILDREN("Kinderbuch"),
    SCIENCE("Wissenschaft"),
    HISTORY("Geschichte");

    protected String name;

    Category(String name){
        
        this.name = name;
    }
}