"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.printBeispiel = printBeispiel;
exports.printBeispielMarkdown = printBeispielMarkdown;
const BeispielTyp_1 = require("../../../de/beispiel/BeispielTyp");
function printBeispiel(caller) {
    return `${caller.typ == BeispielTyp_1.BeispielTyp.TEXT ? "Text-" : "Code-"}Beispiel ${caller.i}`;
}
function printBeispielMarkdown(caller) {
    return `## Beispiel\n${caller.typ == BeispielTyp_1.BeispielTyp.TEXT ? "" : "```javascript\n"}${caller.inhalt}${caller.typ == BeispielTyp_1.BeispielTyp.TEXT ? "" : "\n```"}`;
}
