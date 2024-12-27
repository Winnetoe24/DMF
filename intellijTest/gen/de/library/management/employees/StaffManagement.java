package de.library.management.employees;

public interface  StaffManagement {
    public boolean assignShift(de.library.management.employees.Employee employee, de.library.management.employees.Shift shift);
    public boolean approveTimeOff(de.library.management.employees.TimeOff request);
    public void updateSchedule(de.library.management.employees.Employee employee, de.library.management.employees.WorkSchedule newSchedule);

}