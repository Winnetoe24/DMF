import { IBeispiel } from "../base/IBeispiel";
import { BeispielTyp } from "./BeispielTyp";
import * as delegate from "../../delegates/de/beispiel/BeispielDelegate";

export class Beispiel implements IBeispiel {
    i: number;
    inhalt: string;
    typ: BeispielTyp;
    
    printBeispielMarkdown(): string {
        return delegate.printBeispielMarkdown(this);
    }
}
