import {Beispiel} from "../../../de/beispiel/Beispiel";
import {BeispielTyp} from "../../../de/beispiel/BeispielTyp";


export function printBeispiel(caller: Beispiel): string {
    return `${caller.typ == BeispielTyp.TEXT ? "Text-" : "Code-"}Beispiel ${caller.i}`;
}

export function printBeispielMarkdown(caller: Beispiel): string {
    return `## Beispiel\n${caller.typ == BeispielTyp.TEXT ? "" : "```javascript\n"}${caller.inhalt}${caller.typ == BeispielTyp.TEXT ? "" : "\n```"}`;
}
