package de.library.management.media;

import java.time.LocalDate;
import java.util.Objects;

public class Magazine extends MediaItem {
    protected int issueNumber;
    protected String publisher;
    protected boolean isSubscription;
    protected LocalDate validUntil;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Magazine entity = (Magazine) o;
        return Objects.equals(issueNumber, entity.issueNumber)  && Objects.equals(publisher, entity.publisher)  && Objects.equals(isSubscription, entity.isSubscription)  && Objects.equals(validUntil, entity.validUntil) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(issueNumber, publisher, isSubscription, validUntil);
    }
}