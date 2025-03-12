import { I } from "./I";
import { Tetrapack } from "./Tetrapack";
import * as delegate from "../../../../delegates/de/alex/brand/klein/ApfelsaftDelegate";

export class Apfelsaft extends Tetrapack implements I {

    
    Hi(): void {
        delegate.Hi(this);
    }
    
    Zwei(): void {
        delegate.Zwei(this);
    }
}
