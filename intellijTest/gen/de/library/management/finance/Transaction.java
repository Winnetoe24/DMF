package de.library.management.finance;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class Transaction {
    protected User user;
    protected PaymentMethod paymentMethod;
    protected TransactionType type;
    protected InvoiceDetails invoice;
    protected LocalDate transactionDate;
    protected double amount;
    protected boolean isPaid;
    protected String reference;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Transaction entity = (Transaction) o;
        return Objects.equals(user, entity.user)  && Objects.equals(paymentMethod, entity.paymentMethod)  && Objects.equals(type, entity.type)  && Objects.equals(invoice, entity.invoice)  && Objects.equals(transactionDate, entity.transactionDate)  && Objects.equals(amount, entity.amount)  && Objects.equals(isPaid, entity.isPaid)  && Objects.equals(reference, entity.reference) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, paymentMethod, type, invoice, transactionDate, amount, isPaid, reference);
    }
}