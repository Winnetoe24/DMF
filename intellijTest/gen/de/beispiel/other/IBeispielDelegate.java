package de.beispiel.other;

import java.time.LocalDateTime;
import de.beispiel.hotel.Person;
import java.time.LocalDate;

public interface IBeispielDelegate {
    public Person createPerson(Beispiel caller);

}