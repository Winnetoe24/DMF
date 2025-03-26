import express, {Express, Request, Response} from "express";
import dotenv from "dotenv";
import {Beispiel} from "./de/beispiel/Beispiel"
import {BeispielTyp} from "./de/beispiel/BeispielTyp"
import {Aufgabe} from "./de/beispiel/Aufgabe";

dotenv.config();

const app: Express = express();
const port = process.env.PORT || 3000;

app.get("/", (req: Request, res: Response) => {
    res.send("Express + TypeScript Server");
});

const aufgaben: Record<number, Aufgabe> = {
    1: new Aufgabe(
        "Was ist der Unterschied zwischen 'let' und 'const' in JavaScript?",
        "'let' erlaubt Variablen nach der Deklaration zu ändern, während 'const' nur eine einmalige Zuweisung erlaubt. Der Wert einer 'const' Variable kann nicht geändert werden, aber die Eigenschaften eines Objekts oder Arrays, das mit 'const' deklariert wurde, können geändert werden.",
        1,
        new Beispiel(1,`let i = 1;\nconst ii = 2`, BeispielTyp.CODE)
    ),
    2: new Aufgabe(
        "Erkläre das Konzept der Vererbung in der objektorientierten Programmierung.",
        "Vererbung ist ein Mechanismus, bei dem eine Klasse die Eigenschaften und Methoden einer anderen Klasse erben kann. Die Klasse, die erbt, wird als abgeleitete Klasse oder Unterklasse bezeichnet, während die Klasse, von der geerbt wird, als Basisklasse oder Oberklasse bezeichnet wird. Durch Vererbung können gemeinsame Eigenschaften und Verhalten wiederverwendet werden.",
        2,
        new Beispiel(1,  `Ein Pferd ist genauso ein Tier wie ein Hund.`, BeispielTyp.TEXT)
    ),
}
app.get("/:id", (req: Request, res: Response) => {
    const id: number = Number(req.params["id"]);

    const aufgabe = aufgaben[id];

    if (!aufgabe) {
        res.status(404).send({
            error: 'Aufgabe not found'
        });
        return
    }
    res.setHeader('Content-Type', 'text/markdown');

    res.send(`# ${aufgabe.frage}\n${aufgabe.beispiel.printBeispielMarkdown()}`);
});

app.listen(port, () => {
    console.log(`[server]: Server is running at http://localhost:${port}`);
});