package de.beispiel;

/**
 * Delegate von Beispiel
 * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BeispielDelegate {

    public String printBeispiel(Beispiel caller){
        return "Beispiel: \n" + caller.getInhalt();
    }

    public String printBeispielMarkdown(Beispiel caller){
        return "";
    }
}