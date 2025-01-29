package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class Reminder {
    protected static ReminderDelegate delegate;
    protected User user;
    protected Transaction transaction;
    protected int reminderLevel;
    protected LocalDate sentDate;
    protected LocalDate deadlineDate;
    protected double additionalFee;
    protected boolean isPaid;



    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Transaction getTransaction() {
        return this.transaction;
    }

    public void setTransaction(Transaction transaction) {
        this.transaction = transaction;
    }

    public int getReminderLevel() {
        return this.reminderLevel;
    }

    public void setReminderLevel(int reminderLevel) {
        this.reminderLevel = reminderLevel;
    }

    public LocalDate getSentDate() {
        return this.sentDate;
    }

    public void setSentDate(LocalDate sentDate) {
        this.sentDate = sentDate;
    }

    public LocalDate getDeadlineDate() {
        return this.deadlineDate;
    }

    public void setDeadlineDate(LocalDate deadlineDate) {
        this.deadlineDate = deadlineDate;
    }

    public double getAdditionalFee() {
        return this.additionalFee;
    }

    public void setAdditionalFee(double additionalFee) {
        this.additionalFee = additionalFee;
    }

    public boolean getIsPaid() {
        return this.isPaid;
    }

    public void setIsPaid(boolean isPaid) {
        this.isPaid = isPaid;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Reminder entity = (Reminder) o;
        return Objects.equals(transaction, entity.transaction)  && Objects.equals(reminderLevel, entity.reminderLevel) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(transaction, reminderLevel);
    }
}