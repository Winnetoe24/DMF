package de.library.management.media;
import java.util.Objects;

public class Book extends MediaItem {
    protected String author;
    protected Category category;
    protected MediaType type;
    protected int pageCount;
    protected String publisher;
    protected String language;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Book entity = (Book) o;
        return Objects.equals(author, entity.author)  && Objects.equals(category, entity.category)  && Objects.equals(type, entity.type)  && Objects.equals(pageCount, entity.pageCount)  && Objects.equals(publisher, entity.publisher)  && Objects.equals(language, entity.language) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(author, category, type, pageCount, publisher, language);
    }
}