import { Apfelsaft } from "./Apfelsaft";
import * as delegate from "../../../../delegates/de/alex/brand/klein/TetrapackDelegate";

export class Tetrapack {
    l: bigint;
    sa: Date;
    a: Apfelsaft;
    /**
     * Das ist eine Map
     **/
    i: Map<Apfelsaft, number> = new Map<Apfelsaft, number>();
    
    tata(i: number, t: Tetrapack, sad: bigint): void {
        delegate.tata(this, i, t, sad);
    }
    
    tataZwei(i: number, t: Tetrapack, sad: bigint): void {
        delegate.tataZwei(this, i, t, sad);
    }
}
