package de.beispiel;

import de.base.IBeispiel;
import java.util.Objects;

/**
 **/
public class Beispiel implements IBeispiel {
    protected static BeispielDelegate delegate = new BeispielDelegate();
    protected int i;
    protected String inhalt;
    protected BeispielTyp typ;

    public String printBeispiel(){
        return delegate.printBeispiel(this);
    }

    public String printBeispielMarkdown(){
        return delegate.printBeispielMarkdown(this);
    }

    public int getI() {
        return this.i;
    }

    public void setI(int i) {
        this.i = i;
    }

    public String getInhalt() {
        return this.inhalt;
    }

    public void setInhalt(String inhalt) {
        this.inhalt = inhalt;
    }
    public BeispielTyp getTyp() {
        return this.typ;
    }

    public void setTyp(BeispielTyp typ) {
        this.typ = typ;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Beispiel entity = (Beispiel) o;
        return Objects.equals(typ, entity.typ)  && Objects.equals(i, entity.i)  && Objects.equals(inhalt, entity.inhalt) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(typ, i, inhalt);
    }
}