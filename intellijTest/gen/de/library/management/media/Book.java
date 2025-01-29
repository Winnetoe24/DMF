package de.library.management.media;
import java.util.Objects;

public class Book extends MediaItem {
    protected static BookDelegate delegate;
    protected String author;
    protected Category category;
    protected MediaType type;
    protected int pageCount;
    protected String publisher;
    protected String language;



    public String getAuthor() {
        return this.author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public Category getCategory() {
        return this.category;
    }

    public void setCategory(Category category) {
        this.category = category;
    }

    public MediaType getType() {
        return this.type;
    }

    public void setType(MediaType type) {
        this.type = type;
    }

    public int getPageCount() {
        return this.pageCount;
    }

    public void setPageCount(int pageCount) {
        this.pageCount = pageCount;
    }

    public String getPublisher() {
        return this.publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getLanguage() {
        return this.language;
    }

    public void setLanguage(String language) {
        this.language = language;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Book entity = (Book) o;
        return Objects.equals(isbn, entity.isbn)  && Objects.equals(copyNumber, entity.copyNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(isbn, copyNumber);
    }
}