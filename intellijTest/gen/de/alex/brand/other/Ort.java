package de.alex.brand.other;

import java.time.LocalDateTime;
import java.time.LocalDate;

/**
 **/
public enum Ort {
    VOR_HAUS(1, true, "TODO", java.time.LocalDate.of(2012, 12, 12), java.time.LocalDateTime.of(2012, 1, 1, 0, January, 0, 0), 123L);

    protected int i;
    protected boolean b;
    protected String s;
    protected LocalDate d;
    protected LocalDateTime dt;
    protected long l;

    Ort(int i, boolean b, String s, LocalDate d, LocalDateTime dt, long l){
        
        this.i = i;
        this.b = b;
        this.s = s;
        this.d = d;
        this.dt = dt;
        this.l = l;
    }
}