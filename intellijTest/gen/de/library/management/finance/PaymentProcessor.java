package de.library.management.finance;

public interface  PaymentProcessor {
    public boolean processPayment(de.library.management.users.User user, de.library.management.finance.Transaction transaction);
    public void generateInvoice(de.library.management.finance.Transaction transaction);
    public boolean refundPayment(de.library.management.finance.Transaction transaction, double amount);

}