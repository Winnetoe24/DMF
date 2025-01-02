package de.beispiel.other;

import de.beispiel.hotel.Person;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Objects;

/**
 **/
public class Beispiel {
    protected static BeispielDelegate delegate;
    protected int i;
    protected boolean b;
    protected String s;
    protected LocalDate d;
    protected LocalDateTime dt;
    protected long l;
    protected o object;

    public Person createPerson(){
        return delegate.createPerson(this);
    }

    public int getI() {
        return this.i;
    }

    public void setI(int i) {
        this.i = i;
    }
    public boolean getB() {
        return this.b;
    }

    public void setB(boolean b) {
        this.b = b;
    }

    public String getS() {
        return this.s;
    }

    public void setS(String s) {
        this.s = s;
    }

    public LocalDate getD() {
        return this.d;
    }

    public void setD(LocalDate d) {
        this.d = d;
    }

    public LocalDateTime getDt() {
        return this.dt;
    }

    public void setDt(LocalDateTime dt) {
        this.dt = dt;
    }

    public long getL() {
        return this.l;
    }

    public void setL(long l) {
        this.l = l;
    }

    public o getObject() {
        return this.object;
    }

    public void setObject(o object) {
        this.object = object;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Beispiel entity = (Beispiel) o;
        return Objects.equals(l, entity.l)  && Objects.equals(object, entity.object)  && Objects.equals(i, entity.i)  && Objects.equals(b, entity.b)  && Objects.equals(s, entity.s)  && Objects.equals(d, entity.d)  && Objects.equals(dt, entity.dt) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(l, object, i, b, s, d, dt);
    }
}