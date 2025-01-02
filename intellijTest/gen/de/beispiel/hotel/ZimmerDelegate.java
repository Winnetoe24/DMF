package de.beispiel.hotel;
import java.util.Objects;

public class ZimmerDelegate implements Zeitraum {
    protected long zimmernummer;

    public java.time.LocalDateTime endPunkt(){
        return null;
    }

    public boolean contains(java.time.LocalDateTime zeitpunkt){
        return false;
    }

    public java.time.LocalDateTime startPunkt(){
        return null;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ZimmerDelegate entity = (ZimmerDelegate) o;
        return Objects.equals(zimmernummer, entity.zimmernummer) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(zimmernummer);
    }
}