package de.library.management.media;

import java.time.LocalDate;

/**
 * Basisstruktur für alle Medientypen
 **/
public class MediaItem {
    protected String title;
    protected String isbn;
    protected LocalDate publishedDate;
    protected double price;
    protected int copyNumber;

    public boolean isAvailable(int copyId){
        return false;
    }

}