package de.beispiel.hotel;

import java.time.LocalDate;
import java.util.Objects;

public class Person {
    protected static PersonDelegate delegate;
    protected Ort o;
    protected LocalDate beispieldate;
    protected int me;
    protected int i;


    public Ort getO() {
        return this.o;
    }
    public void setO(Ort o) {
        this.o = o;
    }
    public LocalDate getBeispieldate() {
        return this.beispieldate;
    }
    public void setBeispieldate(LocalDate beispieldate) {
        this.beispieldate = beispieldate;
    }
    public int getMe() {
        return this.me;
    }
    public void setMe(int me) {
        this.me = me;
    }
    public int getI() {
        return this.i;
    }
    public void setI(int i) {
        this.i = i;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Person entity = (Person) o;
        return Objects.equals(i, entity.i)  && Objects.equals(me, entity.me) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, me);
    }
}