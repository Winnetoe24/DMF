package de.smart.city.fintech;

public interface Transactional {
    public boolean validate();
    public String generateHash();
    public boolean verifySignature(String signature);
    public void logTransaction();
    public double calculateFees();

}