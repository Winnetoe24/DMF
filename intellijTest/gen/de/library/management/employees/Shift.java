package de.library.management.employees;

import java.time.LocalDate;
import java.time.LocalDateTime;
import de.library.management.facilities.Building;
import java.util.Objects;

public class Shift {
    protected static ShiftDelegate delegate;
    protected Employee employee;
    protected Building building;
    protected LocalDate date;
    protected LocalDateTime startTime;
    protected LocalDateTime endTime;
    protected String responsibilities;



    public Employee getEmployee() {
        return this.employee;
    }

    public void setEmployee(Employee employee) {
        this.employee = employee;
    }

    public Building getBuilding() {
        return this.building;
    }

    public void setBuilding(Building building) {
        this.building = building;
    }

    public LocalDate getDate() {
        return this.date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public LocalDateTime getStartTime() {
        return this.startTime;
    }

    public void setStartTime(LocalDateTime startTime) {
        this.startTime = startTime;
    }

    public LocalDateTime getEndTime() {
        return this.endTime;
    }

    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    public String getResponsibilities() {
        return this.responsibilities;
    }

    public void setResponsibilities(String responsibilities) {
        this.responsibilities = responsibilities;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Shift entity = (Shift) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(date, entity.date)  && Objects.equals(startTime, entity.startTime) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, date, startTime);
    }
}