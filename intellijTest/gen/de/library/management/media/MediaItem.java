package de.library.management.media;

import java.time.LocalDate;
import java.util.Objects;

/**
 * Basisstruktur für alle Medientypen
 **/
public class MediaItem {
    protected static MediaItemDelegate delegate;
    protected String title;
    protected String isbn;
    protected LocalDate publishedDate;
    protected double price;
    protected int copyNumber;

    public boolean isAvailable(int copyId){
        return delegate.isAvailable(this, copyId);
    }

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    public String getIsbn() {
        return this.isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public LocalDate getPublishedDate() {
        return this.publishedDate;
    }

    public void setPublishedDate(LocalDate publishedDate) {
        this.publishedDate = publishedDate;
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getCopyNumber() {
        return this.copyNumber;
    }

    public void setCopyNumber(int copyNumber) {
        this.copyNumber = copyNumber;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MediaItem entity = (MediaItem) o;
        return Objects.equals(title, entity.title)  && Objects.equals(isbn, entity.isbn)  && Objects.equals(publishedDate, entity.publishedDate)  && Objects.equals(price, entity.price)  && Objects.equals(copyNumber, entity.copyNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(title, isbn, publishedDate, price, copyNumber);
    }
}