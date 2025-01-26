package de.library.management.media;

import java.time.LocalDate;

/**
 * Delegate von MediaItem * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MediaItemDelegate {
    static {
        MediaItem.delegate = new MediaItemDelegate();
    }
    public boolean isAvailable(MediaItem caller, int copyId){
        return false;
    }
}