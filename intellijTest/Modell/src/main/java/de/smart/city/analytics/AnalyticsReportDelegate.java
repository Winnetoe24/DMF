package de.smart.city.analytics;

import java.time.LocalDateTime;

/**
 * Delegate von AnalyticsReport * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AnalyticsReportDelegate {
    static {
        AnalyticsReport.delegate = new AnalyticsReportDelegate();
    }
    public void generatePDF(AnalyticsReport caller){
        ;
    }

}