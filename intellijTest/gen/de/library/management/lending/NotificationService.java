package de.library.management.lending;

import de.library.management.users.User;
import de.library.management.media.MediaItem;

public interface NotificationService {
    public void sendOverdueNotice(User user, MediaItem item);
    public void sendReturnReminder(User user, MediaItem item);
    public boolean checkAvailability(MediaItem item);

}