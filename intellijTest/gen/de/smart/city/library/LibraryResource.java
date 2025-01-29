package de.smart.city.library;

import java.time.LocalDate;
import java.util.Objects;

public class LibraryResource {
    protected static LibraryResourceDelegate delegate;
    protected String resourceId;
    protected LibraryResourceType type;
    protected String title;
    protected LocalDate publicationDate;
    protected String publisher;
    protected String location;
    protected boolean isAvailable;



    public String getResourceId() {
        return this.resourceId;
    }

    public void setResourceId(String resourceId) {
        this.resourceId = resourceId;
    }

    public LibraryResourceType getType() {
        return this.type;
    }

    public void setType(LibraryResourceType type) {
        this.type = type;
    }

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public LocalDate getPublicationDate() {
        return this.publicationDate;
    }

    public void setPublicationDate(LocalDate publicationDate) {
        this.publicationDate = publicationDate;
    }

    public String getPublisher() {
        return this.publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getLocation() {
        return this.location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public boolean getIsAvailable() {
        return this.isAvailable;
    }

    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LibraryResource entity = (LibraryResource) o;
        return Objects.equals(resourceId, entity.resourceId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(resourceId);
    }
}