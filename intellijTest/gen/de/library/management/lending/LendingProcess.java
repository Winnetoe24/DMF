package de.library.management.lending;

import java.time.LocalDate;
import de.library.management.users.User;
import de.library.management.media.MediaItem;
import java.util.Objects;

public class LendingProcess {
    protected User user;
    protected MediaItem item;
    protected LendingStatus status;
    protected LocalDate borrowDate;
    protected LocalDate dueDate;
    protected LocalDate returnDate;


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LendingProcess entity = (LendingProcess) o;
        return Objects.equals(user, entity.user)  && Objects.equals(item, entity.item)  && Objects.equals(status, entity.status)  && Objects.equals(borrowDate, entity.borrowDate)  && Objects.equals(dueDate, entity.dueDate)  && Objects.equals(returnDate, entity.returnDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, item, status, borrowDate, dueDate, returnDate);
    }
}