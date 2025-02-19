package de.smart.city.media_production;

import java.time.LocalDateTime;

/**
 * Delegate von ImpactNotification * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ImpactNotificationDelegate {
    static {
        ImpactNotification.delegate = new ImpactNotificationDelegate();
    }

}