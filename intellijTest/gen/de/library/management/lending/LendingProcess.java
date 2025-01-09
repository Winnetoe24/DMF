package de.library.management.lending;

import java.time.LocalDate;
import de.library.management.users.User;
import de.library.management.media.MediaItem;
import java.util.Objects;

public class LendingProcess {
    protected static LendingProcessDelegate delegate;
    protected User user;
    protected MediaItem item;
    protected LendingStatus status;
    protected LocalDate borrowDate;
    protected LocalDate dueDate;
    protected LocalDate returnDate;



    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public MediaItem getItem() {
        return this.item;
    }

    public void setItem(MediaItem item) {
        this.item = item;
    }

    public LendingStatus getStatus() {
        return this.status;
    }

    public void setStatus(LendingStatus status) {
        this.status = status;
    }

    public LocalDate getBorrowDate() {
        return this.borrowDate;
    }

    public void setBorrowDate(LocalDate borrowDate) {
        this.borrowDate = borrowDate;
    }

    public LocalDate getDueDate() {
        return this.dueDate;
    }

    public void setDueDate(LocalDate dueDate) {
        this.dueDate = dueDate;
    }

    public LocalDate getReturnDate() {
        return this.returnDate;
    }

    public void setReturnDate(LocalDate returnDate) {
        this.returnDate = returnDate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LendingProcess entity = (LendingProcess) o;
        return Objects.equals(user, entity.user)  && Objects.equals(item, entity.item)  && Objects.equals(borrowDate, entity.borrowDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, item, borrowDate);
    }
}