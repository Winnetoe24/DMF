package de.smart.city.library;

/**
 * Delegate von LoanPolicy * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class LoanPolicyDelegate {
    static {
        LoanPolicy.delegate = new LoanPolicyDelegate();
    }
    public double calculateLateFee(LoanPolicy caller, int daysOverdue){
        return 0d;
    }
}