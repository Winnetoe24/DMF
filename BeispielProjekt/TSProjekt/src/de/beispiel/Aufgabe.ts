import { Beispiel } from "./Beispiel";
import * as delegate from "../../delegates/de/beispiel/AufgabeDelegate";

export class Aufgabe {
    beispiel: Beispiel;
    frage: string;
    antwort: string;
    id: number;
}
