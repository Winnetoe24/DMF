package de.library.management.employees;

import java.time.LocalDate;
import java.util.Objects;

public class TimeOff {
    protected static TimeOffDelegate delegate;
    protected Employee employee;
    protected LocalDate startDate;
    protected LocalDate endDate;
    protected String type;
    protected String status;
    protected String notes;



    public Employee getEmployee() {
        return this.employee;
    }

    public void setEmployee(Employee employee) {
        this.employee = employee;
    }

    public LocalDate getStartDate() {
        return this.startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public LocalDate getEndDate() {
        return this.endDate;
    }

    public void setEndDate(LocalDate endDate) {
        this.endDate = endDate;
    }

    public String getType() {
        return this.type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getStatus() {
        return this.status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getNotes() {
        return this.notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        TimeOff entity = (TimeOff) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(startDate, entity.startDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, startDate);
    }
}