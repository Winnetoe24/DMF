package de.library.management.media;

import java.time.LocalDate;
import java.util.Objects;

public class Magazine extends MediaItem {
    protected static MagazineDelegate delegate;
    protected int issueNumber;
    protected String publisher;
    protected boolean isSubscription;
    protected LocalDate validUntil;



    public int getIssueNumber() {
        return this.issueNumber;
    }

    public void setIssueNumber(int issueNumber) {
        this.issueNumber = issueNumber;
    }

    public String getPublisher() {
        return this.publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public boolean getIsSubscription() {
        return this.isSubscription;
    }

    public void setIsSubscription(boolean isSubscription) {
        this.isSubscription = isSubscription;
    }

    public LocalDate getValidUntil() {
        return this.validUntil;
    }

    public void setValidUntil(LocalDate validUntil) {
        this.validUntil = validUntil;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Magazine entity = (Magazine) o;
        return Objects.equals(isbn, entity.isbn)  && Objects.equals(issueNumber, entity.issueNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(isbn, issueNumber);
    }
}