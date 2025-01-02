package de.beispiel.hotel;
import java.util.Objects;

public class Zimmer implements Zeitraum {
    protected static ZimmerDelegate delegate;
    protected long zimmernummer;

    public boolean contains(java.time.LocalDateTime zeitpunkt){
        return delegate(this, zeitpunkt);
    }

    public java.time.LocalDateTime startPunkt(){
        return delegate(this);
    }

    public java.time.LocalDateTime endPunkt(){
        return delegate(this);
    }

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