package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class Transaction {
    protected static TransactionDelegate delegate;
    protected User user;
    protected PaymentMethod paymentMethod;
    protected TransactionType type;
    protected InvoiceDetails invoice;
    protected LocalDate transactionDate;
    protected double amount;
    protected boolean isPaid;
    protected String reference;



    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public PaymentMethod getPaymentMethod() {
        return this.paymentMethod;
    }

    public void setPaymentMethod(PaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    public TransactionType getType() {
        return this.type;
    }

    public void setType(TransactionType type) {
        this.type = type;
    }

    public InvoiceDetails getInvoice() {
        return this.invoice;
    }

    public void setInvoice(InvoiceDetails invoice) {
        this.invoice = invoice;
    }

    public LocalDate getTransactionDate() {
        return this.transactionDate;
    }

    public void setTransactionDate(LocalDate transactionDate) {
        this.transactionDate = transactionDate;
    }

    public double getAmount() {
        return this.amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public boolean getIsPaid() {
        return this.isPaid;
    }

    public void setIsPaid(boolean isPaid) {
        this.isPaid = isPaid;
    }

    public String getReference() {
        return this.reference;
    }

    public void setReference(String reference) {
        this.reference = reference;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Transaction entity = (Transaction) o;
        return Objects.equals(reference, entity.reference)  && Objects.equals(transactionDate, entity.transactionDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(reference, transactionDate);
    }
}