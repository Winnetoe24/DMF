package de.beispiel.hotel;

public interface IZimmerDelegate {
    public boolean contains(Zimmer caller, java.time.LocalDateTime zeitpunkt);
    public java.time.LocalDateTime startPunkt(Zimmer caller);
    public java.time.LocalDateTime endPunkt(Zimmer caller);

}