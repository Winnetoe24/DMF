package de.library.management.employees;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 * Arbeitsplan
 **/
public class WorkSchedule {
    protected static WorkScheduleDelegate delegate;
    protected LocalDateTime regularStart;
    protected LocalDateTime regularEnd;
    protected int weeklyHours;
    protected String shiftPattern;
    protected boolean includesWeekends;



    public LocalDateTime getRegularStart() {
        return this.regularStart;
    }

    public void setRegularStart(LocalDateTime regularStart) {
        this.regularStart = regularStart;
    }

    public LocalDateTime getRegularEnd() {
        return this.regularEnd;
    }

    public void setRegularEnd(LocalDateTime regularEnd) {
        this.regularEnd = regularEnd;
    }

    public int getWeeklyHours() {
        return this.weeklyHours;
    }

    public void setWeeklyHours(int weeklyHours) {
        this.weeklyHours = weeklyHours;
    }

    public String getShiftPattern() {
        return this.shiftPattern;
    }

    public void setShiftPattern(String shiftPattern) {
        this.shiftPattern = shiftPattern;
    }

    public boolean getIncludesWeekends() {
        return this.includesWeekends;
    }

    public void setIncludesWeekends(boolean includesWeekends) {
        this.includesWeekends = includesWeekends;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WorkSchedule entity = (WorkSchedule) o;
        return Objects.equals(weeklyHours, entity.weeklyHours)  && Objects.equals(shiftPattern, entity.shiftPattern)  && Objects.equals(includesWeekends, entity.includesWeekends)  && Objects.equals(regularStart, entity.regularStart)  && Objects.equals(regularEnd, entity.regularEnd) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(weeklyHours, shiftPattern, includesWeekends, regularStart, regularEnd);
    }
}