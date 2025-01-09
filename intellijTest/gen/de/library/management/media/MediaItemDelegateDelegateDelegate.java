package de.library.management.media;

import java.time.LocalDate;

/**
 * Delegate von MediaItem * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class MediaItemDelegateDelegateDelegate {
    static {
        MediaItemDelegateDelegate.delegate = new MediaItemDelegateDelegateDelegate();
    }
    public boolean isAvailable(MediaItemDelegateDelegate caller, int copyId){
        return false;
    }
}