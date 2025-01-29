package de.library.management.finance;

import de.library.management.users.User;

public interface PaymentProcessor {
    public boolean processPayment(User user, Transaction transaction);
    public void generateInvoice(Transaction transaction);
    public boolean refundPayment(Transaction transaction, double amount);

}