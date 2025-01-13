package de.smart.city.fintech;

public interface Auditable {
    /**
     * TODO []
     **/
    public String getAuditTrail();
    public void addAuditEntry(String entry);
    public boolean isCompliant();
    public java.time.LocalDate getLastAuditDate();
    public String getAuditor();

}