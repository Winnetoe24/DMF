package de.library.management.finance;
import java.util.Objects;

public class Budget {
    protected int year;
    protected int month;
    protected String category;
    protected double plannedAmount;
    protected double actualAmount;
    protected String notes;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Budget entity = (Budget) o;
        return Objects.equals(year, entity.year)  && Objects.equals(month, entity.month)  && Objects.equals(category, entity.category)  && Objects.equals(plannedAmount, entity.plannedAmount)  && Objects.equals(actualAmount, entity.actualAmount)  && Objects.equals(notes, entity.notes) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(year, month, category, plannedAmount, actualAmount, notes);
    }
}