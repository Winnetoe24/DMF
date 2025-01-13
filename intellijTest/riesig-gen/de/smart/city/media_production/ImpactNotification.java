package de.smart.city.media_production;

import java.time.LocalDateTime;
import java.util.Objects;

public class ImpactNotification {
    protected static ImpactNotificationDelegate delegate;
    protected String notificationId;
    protected FilmPermit permit;
    protected LocalDateTime noticeTime;
    protected boolean requiresEvacuation;



    public String getNotificationId() {
        return this.notificationId;
    }

    public void setNotificationId(String notificationId) {
        this.notificationId = notificationId;
    }

    public FilmPermit getPermit() {
        return this.permit;
    }

    public void setPermit(FilmPermit permit) {
        this.permit = permit;
    }

    public LocalDateTime getNoticeTime() {
        return this.noticeTime;
    }

    public void setNoticeTime(LocalDateTime noticeTime) {
        this.noticeTime = noticeTime;
    }

    public boolean getRequiresEvacuation() {
        return this.requiresEvacuation;
    }

    public void setRequiresEvacuation(boolean requiresEvacuation) {
        this.requiresEvacuation = requiresEvacuation;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ImpactNotification entity = (ImpactNotification) o;
        return Objects.equals(notificationId, entity.notificationId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(notificationId);
    }
}