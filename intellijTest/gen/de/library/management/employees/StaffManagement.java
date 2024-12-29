package de.library.management.employees;

public interface StaffManagement {
    public boolean assignShift(Employee employee, Shift shift);
    public boolean approveTimeOff(TimeOff request);
    public void updateSchedule(Employee employee, WorkSchedule newSchedule);

}