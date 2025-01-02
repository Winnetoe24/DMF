package de.beispiel.hotel;

public interface Zeitraum {
    public boolean contains(java.time.LocalDateTime zeitpunkt);
    public java.time.LocalDateTime startPunkt();
    public java.time.LocalDateTime endPunkt();

}