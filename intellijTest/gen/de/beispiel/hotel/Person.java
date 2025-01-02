package de.beispiel.hotel;

import java.time.LocalDate;
import java.util.Objects;

public class PersonDelegate {
    protected Ort o;
    protected LocalDate beispieldate;
    protected int me;
    protected int i;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PersonDelegate entity = (PersonDelegate) o;
        return Objects.equals(i, entity.i)  && Objects.equals(me, entity.me) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, me);
    }
}