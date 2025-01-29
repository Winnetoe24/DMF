package de.smart.city.signage;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class DigitalSign extends Asset {
    protected static DigitalSignDelegate delegate;
    protected SignType type;
    protected ContentType contentType;
    protected String resolution;
    protected boolean isInteractive;



    public SignType getType() {
        return this.type;
    }

    public void setType(SignType type) {
        this.type = type;
    }

    public ContentType getContentType() {
        return this.contentType;
    }

    public void setContentType(ContentType contentType) {
        this.contentType = contentType;
    }

    public String getResolution() {
        return this.resolution;
    }

    public void setResolution(String resolution) {
        this.resolution = resolution;
    }

    public boolean getIsInteractive() {
        return this.isInteractive;
    }

    public void setIsInteractive(boolean isInteractive) {
        this.isInteractive = isInteractive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        DigitalSign entity = (DigitalSign) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}