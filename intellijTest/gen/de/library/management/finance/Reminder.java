package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class Reminder {
    protected User user;
    protected Transaction transaction;
    protected int reminderLevel;
    protected LocalDate sentDate;
    protected LocalDate deadlineDate;
    protected double additionalFee;
    protected boolean isPaid;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Reminder entity = (Reminder) o;
        return Objects.equals(user, entity.user)  && Objects.equals(transaction, entity.transaction)  && Objects.equals(reminderLevel, entity.reminderLevel)  && Objects.equals(sentDate, entity.sentDate)  && Objects.equals(deadlineDate, entity.deadlineDate)  && Objects.equals(additionalFee, entity.additionalFee)  && Objects.equals(isPaid, entity.isPaid) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, transaction, reminderLevel, sentDate, deadlineDate, additionalFee, isPaid);
    }
}