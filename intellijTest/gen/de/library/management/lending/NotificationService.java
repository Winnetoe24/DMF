package de.library.management.lending;

public interface  NotificationService {
    public void sendOverdueNotice(de.library.management.users.User user, de.library.management.media.MediaItem item);
    public void sendReturnReminder(de.library.management.users.User user, de.library.management.media.MediaItem item);
    public boolean checkAvailability(de.library.management.media.MediaItem item);

}