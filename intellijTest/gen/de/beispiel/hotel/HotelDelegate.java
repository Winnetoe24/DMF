package de.beispiel.hotel;

import de.beispiel.other.Beispiel;
import java.util.Objects;

public class HotelDelegate {
    /**
     * Kommentar über Referenz
     **/
    protected Zimmer zimmer;
    protected String name;
    protected Beispiel bsp;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        HotelDelegate entity = (HotelDelegate) o;
        return Objects.equals(name, entity.name) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}