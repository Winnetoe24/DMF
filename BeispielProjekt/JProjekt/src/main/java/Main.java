import de.beispiel.Aufgabe;
import de.beispiel.Beispiel;
import de.beispiel.BeispielTyp;

import java.io.IOException;
import java.util.Arrays;
import java.util.List;
public class Main {
    private static final List<Aufgabe> aufgaben = Arrays.asList(createAufgabe(1,
            "Was ist der Unterschied zwischen 'let' und 'const' in JavaScript?",
            "'let' erlaubt Variablen nach der Deklaration zu ändern, während 'const' nur eine einmalige Zuweisung erlaubt. Der Wert einer 'const' Variable kann nicht geändert werden, aber die Eigenschaften eines Objekts oder Arrays, das mit 'const' deklariert wurde, können geändert werden.",
            "let i = 1;\nconst ii = 2",
            BeispielTyp.CODE), createAufgabe(2,
            "Erkläre das Konzept der Vererbung in der objektorientierten Programmierung.",
            "Vererbung ist ein Mechanismus, bei dem eine Klasse die Eigenschaften und Methoden einer anderen Klasse erben kann. Die Klasse, die erbt, wird als abgeleitete Klasse oder Unterklasse bezeichnet, während die Klasse, von der geerbt wird, als Basisklasse oder Oberklasse bezeichnet wird. Durch Vererbung können gemeinsame Eigenschaften und Verhalten wiederverwendet werden.",
            "Ein Pferd ist genauso ein Tier wie ein Hund.",
            BeispielTyp.TEXT));

    public static void main(String[] args) {
        aufgaben.forEach(aufgabe -> {
            System.out.println();
            System.out.println("Frage: " + aufgabe.getFrage());
            System.out.println(aufgabe.getBeispiel().printBeispiel());
            try {
                System.in.read();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Antwort: "+aufgabe.getAntwort());
        });
    }

    private static Aufgabe createAufgabe(int id, String frage, String antwort, String beispiel, BeispielTyp beispielTyp) {
        Aufgabe aufgabe = new Aufgabe();
        aufgabe.setId(id);
        aufgabe.setFrage(frage);
        aufgabe.setAntwort(antwort);
        aufgabe.setBeispiel(new Beispiel());
        aufgabe.getBeispiel().setTyp(beispielTyp);
        aufgabe.getBeispiel().setInhalt(beispiel);
        return aufgabe;
    }
}
