package de.library.management.employees;

import java.time.LocalDate;
import java.util.Objects;

public class TimeOff {
    protected Employee employee;
    protected LocalDate startDate;
    protected LocalDate endDate;
    protected String type;
    protected String status;
    protected String notes;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TimeOff entity = (TimeOff) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(startDate, entity.startDate)  && Objects.equals(endDate, entity.endDate)  && Objects.equals(type, entity.type)  && Objects.equals(status, entity.status)  && Objects.equals(notes, entity.notes) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, startDate, endDate, type, status, notes);
    }
}