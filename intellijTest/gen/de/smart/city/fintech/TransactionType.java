package de.smart.city.fintech;

/**
 * Detailed enumerations
 **/
public enum TransactionType {
    PAYMENT("Payment", 0.1d),
    TRANSFER("Transfer", 0.2d),
    EXCHANGE("Currency Exchange", 0.3d),
    INVESTMENT("Investment", 0.4d),
    LOAN("Loan Disbursement", 0.5d);

    protected String category;
    protected double feePercentage;

    TransactionType(String category, double feePercentage){
        
        this.category = category;
        this.feePercentage = feePercentage;
    }
}