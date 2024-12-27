package de.library.management.media;

/**
 * Kategorisierung der Medien
 **/
public enum Category {
    FICTION("TODO"),
    NON_FICTION("TODO"),
    CHILDREN("TODO"),
    SCIENCE("TODO"),
    HISTORY("TODO");

    protected String name;

    Category(String name){
        
        this.name = name;
    }
}