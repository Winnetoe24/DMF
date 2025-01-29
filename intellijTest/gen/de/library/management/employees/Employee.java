package de.library.management.employees;

import java.time.LocalDate;
import de.library.management.facilities.Building;
import java.util.Objects;

public class Employee {
    protected static EmployeeDelegate delegate;
    protected String employeeId;
    protected String firstName;
    protected String lastName;
    protected Position position;
    protected Department department;
    /**
     * ref .Qualification[] qualifications;
     **/
    protected WorkSchedule schedule;
    protected Building workplace;
    protected LocalDate hireDate;
    protected String email;
    protected String phone;



    public String getEmployeeId() {
        return this.employeeId;
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Position getPosition() {
        return this.position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public Department getDepartment() {
        return this.department;
    }

    public void setDepartment(Department department) {
        this.department = department;
    }

    /**
     * ref .Qualification[] qualifications;
     **/
    public WorkSchedule getSchedule() {
        return this.schedule;
    }

    /**
     * ref .Qualification[] qualifications;
     **/
    public void setSchedule(WorkSchedule schedule) {
        this.schedule = schedule;
    }

    public Building getWorkplace() {
        return this.workplace;
    }

    public void setWorkplace(Building workplace) {
        this.workplace = workplace;
    }

    public LocalDate getHireDate() {
        return this.hireDate;
    }

    public void setHireDate(LocalDate hireDate) {
        this.hireDate = hireDate;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return this.phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Employee entity = (Employee) o;
        return Objects.equals(employeeId, entity.employeeId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employeeId);
    }
}