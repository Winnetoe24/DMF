package de.smart.city.research_facilities;
import java.util.Objects;

public class ResourceSchedule {
    protected static ResourceScheduleDelegate delegate;
    protected String scheduleId;
    protected ResearchEquipment equipment;
    protected boolean hasConflicts;
    /**
     * TODO []
     **/
    protected String maintenanceWindows;
    protected boolean isOptimized;



    public String getScheduleId() {
        return this.scheduleId;
    }

    public void setScheduleId(String scheduleId) {
        this.scheduleId = scheduleId;
    }

    public ResearchEquipment getEquipment() {
        return this.equipment;
    }

    public void setEquipment(ResearchEquipment equipment) {
        this.equipment = equipment;
    }

    public boolean getHasConflicts() {
        return this.hasConflicts;
    }

    public void setHasConflicts(boolean hasConflicts) {
        this.hasConflicts = hasConflicts;
    }

    /**
     * TODO []
     **/
    public String getMaintenanceWindows() {
        return this.maintenanceWindows;
    }

    /**
     * TODO []
     **/
    public void setMaintenanceWindows(String maintenanceWindows) {
        this.maintenanceWindows = maintenanceWindows;
    }

    public boolean getIsOptimized() {
        return this.isOptimized;
    }

    public void setIsOptimized(boolean isOptimized) {
        this.isOptimized = isOptimized;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ResourceSchedule entity = (ResourceSchedule) o;
        return Objects.equals(scheduleId, entity.scheduleId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(scheduleId);
    }
}