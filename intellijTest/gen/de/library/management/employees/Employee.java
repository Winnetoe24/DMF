package de.library.management.employees;

import java.time.LocalDate;
import de.library.management.facilities.Building;
import java.util.Objects;

public class Employee {
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


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Employee entity = (Employee) o;
        return Objects.equals(employeeId, entity.employeeId)  && Objects.equals(firstName, entity.firstName)  && Objects.equals(lastName, entity.lastName)  && Objects.equals(position, entity.position)  && Objects.equals(department, entity.department)  && Objects.equals(schedule, entity.schedule)  && Objects.equals(workplace, entity.workplace)  && Objects.equals(hireDate, entity.hireDate)  && Objects.equals(email, entity.email)  && Objects.equals(phone, entity.phone) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employeeId, firstName, lastName, position, department, schedule, workplace, hireDate, email, phone);
    }
}