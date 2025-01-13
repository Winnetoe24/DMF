package de.smart.city.research_facilities;

/**
 * Delegate von ResourceSchedule * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ResourceScheduleDelegate {
    static {
        ResourceSchedule.delegate = new ResourceScheduleDelegate();
    }

}