package de.library.management.media;

import java.time.LocalDate;

/**
 * Delegate von MediaItem * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MediaItemDelegateDelegate {
    static {
        MediaItemDelegate.delegate = new MediaItemDelegateDelegate();
    }
    public boolean isAvailable(MediaItemDelegate caller, int copyId){
        return false;
    }
}