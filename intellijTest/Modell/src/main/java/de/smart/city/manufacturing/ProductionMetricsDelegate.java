package de.smart.city.manufacturing;

/**
 * Delegate von ProductionMetrics * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class ProductionMetricsDelegate {
    static {
        ProductionMetrics.delegate = new ProductionMetricsDelegate();
    }
    public boolean isOnTarget(ProductionMetrics caller){
        return false;
    }

    public double calculateOEE(ProductionMetrics caller){
        return 0d;
    }

    public double getVariance(ProductionMetrics caller){
        return 0d;
    }
}