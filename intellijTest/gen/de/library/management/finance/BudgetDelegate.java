package de.library.management.finance;

/**
 * Delegate von Budget * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class BudgetDelegate {
    static {
        Budget.delegate = new BudgetDelegate();
    }

}