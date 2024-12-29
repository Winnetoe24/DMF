package de.library.management.employees;

import java.time.LocalDate;
import java.util.Objects;

public class Performance {
    protected Employee employee;
    protected Employee evaluator;
    protected LocalDate evaluationDate;
    protected int rating;
    protected String feedback;
    protected String goals;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Performance entity = (Performance) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(evaluator, entity.evaluator)  && Objects.equals(evaluationDate, entity.evaluationDate)  && Objects.equals(rating, entity.rating)  && Objects.equals(feedback, entity.feedback)  && Objects.equals(goals, entity.goals) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, evaluator, evaluationDate, rating, feedback, goals);
    }
}