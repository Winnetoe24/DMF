package de.smart.city.library;

import java.time.LocalDateTime;
import java.util.Objects;

public class LoanTransaction {
    protected static LoanTransactionDelegate delegate;
    protected String loanId;
    protected LibraryMember member;
    protected LibraryResource resource;
    protected LocalDateTime borrowDate;
    protected LocalDateTime dueDate;
    protected LocalDateTime returnDate;
    protected boolean isOverdue;
    protected double fineAmount;



    public String getLoanId() {
        return this.loanId;
    }

    public void setLoanId(String loanId) {
        this.loanId = loanId;
    }

    public LibraryMember getMember() {
        return this.member;
    }

    public void setMember(LibraryMember member) {
        this.member = member;
    }

    public LibraryResource getResource() {
        return this.resource;
    }

    public void setResource(LibraryResource resource) {
        this.resource = resource;
    }

    public LocalDateTime getBorrowDate() {
        return this.borrowDate;
    }

    public void setBorrowDate(LocalDateTime borrowDate) {
        this.borrowDate = borrowDate;
    }

    public LocalDateTime getDueDate() {
        return this.dueDate;
    }

    public void setDueDate(LocalDateTime dueDate) {
        this.dueDate = dueDate;
    }

    public LocalDateTime getReturnDate() {
        return this.returnDate;
    }

    public void setReturnDate(LocalDateTime returnDate) {
        this.returnDate = returnDate;
    }

    public boolean getIsOverdue() {
        return this.isOverdue;
    }

    public void setIsOverdue(boolean isOverdue) {
        this.isOverdue = isOverdue;
    }

    public double getFineAmount() {
        return this.fineAmount;
    }

    public void setFineAmount(double fineAmount) {
        this.fineAmount = fineAmount;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LoanTransaction entity = (LoanTransaction) o;
        return Objects.equals(loanId, entity.loanId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(loanId);
    }
}