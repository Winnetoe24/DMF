package de.library.management.finance;

import java.time.LocalDate;

/**
 * Rechnungsstruktur
 **/
public class InvoiceDetails {
    protected String invoiceNumber;
    protected LocalDate issueDate;
    protected LocalDate dueDate;
    protected String description;
    protected double subtotal;
    protected double taxAmount;
    protected TaxRate taxRate;



}