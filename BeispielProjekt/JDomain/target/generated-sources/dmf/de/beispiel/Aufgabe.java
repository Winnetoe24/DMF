package de.beispiel;
import java.util.Objects;

public class Aufgabe {
    protected static AufgabeDelegate delegate = new AufgabeDelegate();
    protected Beispiel beispiel;
    protected String frage;
    protected String antwort;
    protected int id;



    public Beispiel getBeispiel() {
        return this.beispiel;
    }

    public void setBeispiel(Beispiel beispiel) {
        this.beispiel = beispiel;
    }

    public String getFrage() {
        return this.frage;
    }

    public void setFrage(String frage) {
        this.frage = frage;
    }

    public String getAntwort() {
        return this.antwort;
    }

    public void setAntwort(String antwort) {
        this.antwort = antwort;
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Aufgabe entity = (Aufgabe) o;
        return Objects.equals(id, entity.id) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}