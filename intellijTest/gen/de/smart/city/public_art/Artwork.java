package de.smart.city.public_art;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class Artwork extends Asset {
    protected static ArtworkDelegate delegate;
    protected ArtType type;
    protected ArtistType artistType;
    protected boolean requiresRestoration;
    protected String materials;



    public ArtType getType() {
        return this.type;
    }

    public void setType(ArtType type) {
        this.type = type;
    }

    public ArtistType getArtistType() {
        return this.artistType;
    }

    public void setArtistType(ArtistType artistType) {
        this.artistType = artistType;
    }

    public boolean getRequiresRestoration() {
        return this.requiresRestoration;
    }

    public void setRequiresRestoration(boolean requiresRestoration) {
        this.requiresRestoration = requiresRestoration;
    }

    public String getMaterials() {
        return this.materials;
    }

    public void setMaterials(String materials) {
        this.materials = materials;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Artwork entity = (Artwork) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}