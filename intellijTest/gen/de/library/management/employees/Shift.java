package de.library.management.employees;

import java.time.LocalDateTime;
import de.library.management.facilities.Building;
import java.time.LocalDate;
import java.util.Objects;

public class Shift {
    protected Employee employee;
    protected Building building;
    protected LocalDate date;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String responsibilities;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Shift entity = (Shift) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(building, entity.building)  && Objects.equals(date, entity.date)  && Objects.equals(startTime, entity.startTime)  && Objects.equals(endTime, entity.endTime)  && Objects.equals(responsibilities, entity.responsibilities) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, building, date, startTime, endTime, responsibilities);
    }
}