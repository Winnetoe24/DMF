package de.library.management.finance;
import java.util.Objects;

public class Budget {
    protected static BudgetDelegate delegate;
    protected int year;
    protected int month;
    protected String category;
    protected double plannedAmount;
    protected double actualAmount;
    protected String notes;



    public int getYear() {
        return this.year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMonth() {
        return this.month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public String getCategory() {
        return this.category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public double getPlannedAmount() {
        return this.plannedAmount;
    }

    public void setPlannedAmount(double plannedAmount) {
        this.plannedAmount = plannedAmount;
    }

    public double getActualAmount() {
        return this.actualAmount;
    }

    public void setActualAmount(double actualAmount) {
        this.actualAmount = actualAmount;
    }

    public String getNotes() {
        return this.notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Budget entity = (Budget) o;
        return Objects.equals(year, entity.year)  && Objects.equals(month, entity.month)  && Objects.equals(category, entity.category) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(year, month, category);
    }
}