package de.beispiel.hotel;

import java.time.LocalDate;
import java.util.Objects;

public class Person {
    protected Ort o;
    protected LocalDate beispieldate;
    protected int me;
    protected int i;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Person entity = (Person) o;
        return Objects.equals(o, entity.o)  && Objects.equals(beispieldate, entity.beispieldate)  && Objects.equals(me, entity.me)  && Objects.equals(i, entity.i) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(o, beispieldate, me, i);
    }
}