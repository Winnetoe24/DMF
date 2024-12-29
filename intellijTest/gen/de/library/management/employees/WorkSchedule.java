package de.library.management.employees;

import java.time.LocalDateTime;

/**
 * Arbeitsplan
 **/
public class WorkSchedule {
    protected LocalDateTime regularStart;
    protected LocalDateTime regularEnd;
    protected int weeklyHours;
    protected String shiftPattern;
    protected boolean includesWeekends;



}