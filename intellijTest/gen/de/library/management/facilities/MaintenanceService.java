package de.library.management.facilities;

public interface  MaintenanceService {
    public void scheduleRoutineMaintenance(de.library.management.facilities.Room room);
    public void reportIssue(de.library.management.facilities.Equipment equipment, String issue);
    public boolean checkAvailability(de.library.management.facilities.Room room, java.time.LocalDate date, java.time.LocalDateTime startTime, java.time.LocalDateTime endTime);

}