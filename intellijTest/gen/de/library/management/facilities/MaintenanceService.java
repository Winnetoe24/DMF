package de.library.management.facilities;

public interface MaintenanceService {
    public void scheduleRoutineMaintenance(Room room);
    public void reportIssue(Equipment equipment, String issue);
    public boolean checkAvailability(Room room, java.time.LocalDate date, java.time.LocalDateTime startTime, java.time.LocalDateTime endTime);

}