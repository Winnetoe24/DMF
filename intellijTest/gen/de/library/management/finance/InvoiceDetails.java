package de.library.management.finance;

import java.time.LocalDate;
import java.util.Objects;

/**
 * Rechnungsstruktur
 **/
public class InvoiceDetails {
    protected static InvoiceDetailsDelegate delegate;
    protected String invoiceNumber;
    protected LocalDate issueDate;
    protected LocalDate dueDate;
    protected String description;
    protected double subtotal;
    protected double taxAmount;
    protected TaxRate taxRate;



    public String getInvoiceNumber() {
        return this.invoiceNumber;
    }

    public void setInvoiceNumber(String invoiceNumber) {
        this.invoiceNumber = invoiceNumber;
    }

    public LocalDate getIssueDate() {
        return this.issueDate;
    }

    public void setIssueDate(LocalDate issueDate) {
        this.issueDate = issueDate;
    }

    public LocalDate getDueDate() {
        return this.dueDate;
    }

    public void setDueDate(LocalDate dueDate) {
        this.dueDate = dueDate;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getSubtotal() {
        return this.subtotal;
    }

    public void setSubtotal(double subtotal) {
        this.subtotal = subtotal;
    }

    public double getTaxAmount() {
        return this.taxAmount;
    }

    public void setTaxAmount(double taxAmount) {
        this.taxAmount = taxAmount;
    }

    public TaxRate getTaxRate() {
        return this.taxRate;
    }

    public void setTaxRate(TaxRate taxRate) {
        this.taxRate = taxRate;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        InvoiceDetails entity = (InvoiceDetails) o;
        return Objects.equals(subtotal, entity.subtotal)  && Objects.equals(taxAmount, entity.taxAmount)  && Objects.equals(taxRate, entity.taxRate)  && Objects.equals(invoiceNumber, entity.invoiceNumber)  && Objects.equals(issueDate, entity.issueDate)  && Objects.equals(dueDate, entity.dueDate)  && Objects.equals(description, entity.description) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(subtotal, taxAmount, taxRate, invoiceNumber, issueDate, dueDate, description);
    }
}