package de.beispiel.hotel;

import de.beispiel.other.Beispiel;
import java.util.Objects;

public class Hotel {
    protected static HotelDelegate delegate;
    /**
     * Kommentar über Referenz
     **/
    protected Zimmer zimmer;
    protected String name;
    protected Beispiel bsp;


    /**
     * Kommentar über Referenz
     **/
    public Zimmer getZimmer() {
        return this.zimmer;
    }
    /**
     * Kommentar über Referenz
     **/
    public void setZimmer(Zimmer zimmer) {
        this.zimmer = zimmer;
    }
    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Beispiel getBsp() {
        return this.bsp;
    }
    public void setBsp(Beispiel bsp) {
        this.bsp = bsp;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Hotel entity = (Hotel) o;
        return Objects.equals(name, entity.name) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}