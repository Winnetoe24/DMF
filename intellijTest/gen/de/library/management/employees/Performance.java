package de.library.management.employees;

import java.time.LocalDate;
import java.util.Objects;

public class Performance {
    protected static PerformanceDelegate delegate;
    protected Employee employee;
    protected Employee evaluator;
    protected LocalDate evaluationDate;
    protected int rating;
    protected String feedback;
    protected String goals;



    public Employee getEmployee() {
        return this.employee;
    }

    public void setEmployee(Employee employee) {
        this.employee = employee;
    }

    public Employee getEvaluator() {
        return this.evaluator;
    }

    public void setEvaluator(Employee evaluator) {
        this.evaluator = evaluator;
    }

    public LocalDate getEvaluationDate() {
        return this.evaluationDate;
    }

    public void setEvaluationDate(LocalDate evaluationDate) {
        this.evaluationDate = evaluationDate;
    }

    public int getRating() {
        return this.rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public String getFeedback() {
        return this.feedback;
    }

    public void setFeedback(String feedback) {
        this.feedback = feedback;
    }

    public String getGoals() {
        return this.goals;
    }

    public void setGoals(String goals) {
        this.goals = goals;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Performance entity = (Performance) o;
        return Objects.equals(employee, entity.employee)  && Objects.equals(evaluationDate, entity.evaluationDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employee, evaluationDate);
    }
}