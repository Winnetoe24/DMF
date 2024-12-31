package de.beispiel.other;

import java.time.LocalDate;
import java.time.LocalDateTime;
import de.beispiel.hotel.Person;
import java.util.Objects;

/**
 **/
public class Beispiel {
    protected int i;
    protected boolean b;
    protected String s;
    protected LocalDate d;
    protected LocalDateTime dt;
    protected long l;
    protected o object;

    public Person createPerson(){
        return null;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Beispiel entity = (Beispiel) o;
        return Objects.equals(i, entity.i)  && Objects.equals(b, entity.b)  && Objects.equals(s, entity.s)  && Objects.equals(d, entity.d)  && Objects.equals(dt, entity.dt)  && Objects.equals(l, entity.l)  && Objects.equals(object, entity.object) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, b, s, d, dt, l, object);
    }
}