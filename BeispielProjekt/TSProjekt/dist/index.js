"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const dotenv_1 = __importDefault(require("dotenv"));
const Beispiel_1 = require("./de/beispiel/Beispiel");
const BeispielTyp_1 = require("./de/beispiel/BeispielTyp");
const Aufgabe_1 = require("./de/beispiel/Aufgabe");
dotenv_1.default.config();
const app = (0, express_1.default)();
const port = process.env.PORT || 3000;
app.get("/", (req, res) => {
    res.send("Express + TypeScript Server");
});
const aufgaben = {
    1: new Aufgabe_1.Aufgabe("Was ist der Unterschied zwischen 'let' und 'const' in JavaScript?", "'let' erlaubt Variablen nach der Deklaration zu ändern, während 'const' nur eine einmalige Zuweisung erlaubt. Der Wert einer 'const' Variable kann nicht geändert werden, aber die Eigenschaften eines Objekts oder Arrays, das mit 'const' deklariert wurde, können geändert werden.", 1, new Beispiel_1.Beispiel(1, `let i = 1;
        const ii = 2`, BeispielTyp_1.BeispielTyp.CODE)),
    2: new Aufgabe_1.Aufgabe("Erkläre das Konzept der Vererbung in der objektorientierten Programmierung.", "Vererbung ist ein Mechanismus, bei dem eine Klasse die Eigenschaften und Methoden einer anderen Klasse erben kann. Die Klasse, die erbt, wird als abgeleitete Klasse oder Unterklasse bezeichnet, während die Klasse, von der geerbt wird, als Basisklasse oder Oberklasse bezeichnet wird. Durch Vererbung können gemeinsame Eigenschaften und Verhalten wiederverwendet werden.", 2, new Beispiel_1.Beispiel(1, `Ein Pferd ist genauso ein Tier wie ein Hund.`, BeispielTyp_1.BeispielTyp.TEXT)),
};
app.get("/:id", (req, res) => {
    const id = Number(req.params["id"]);
    const aufgabe = aufgaben[id];
    if (!aufgabe) {
        res.status(404).send({
            error: 'Aufgabe not found'
        });
        return;
    }
    res.setHeader('Content-Type', 'text/markdown');
    res.send(`# ${aufgabe.frage}\n${aufgabe.beispiel.printBeispielMarkdown()}`);
});
app.listen(port, () => {
    console.log(`[server]: Server is running at http://localhost:${port}`);
});
