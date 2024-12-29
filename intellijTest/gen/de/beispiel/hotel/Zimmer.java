package de.beispiel.hotel;
import java.util.Objects;

public class Zimmer {
    protected long zimmernummer;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Zimmer entity = (Zimmer) o;
        return Objects.equals(zimmernummer, entity.zimmernummer) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(zimmernummer);
    }
}