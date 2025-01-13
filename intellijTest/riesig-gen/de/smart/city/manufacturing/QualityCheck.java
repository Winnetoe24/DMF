package de.smart.city.manufacturing;

import java.time.LocalDateTime;
import java.util.Objects;

public class QualityCheck {
    protected static QualityCheckDelegate delegate;
    protected String checkId;
    protected ProductionLine line;
    protected LocalDateTime timestamp;
    protected String inspector;
    protected boolean passed;
    protected String action;



    public String getCheckId() {
        return this.checkId;
    }

    public void setCheckId(String checkId) {
        this.checkId = checkId;
    }

    public ProductionLine getLine() {
        return this.line;
    }

    public void setLine(ProductionLine line) {
        this.line = line;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public String getInspector() {
        return this.inspector;
    }

    public void setInspector(String inspector) {
        this.inspector = inspector;
    }

    public boolean getPassed() {
        return this.passed;
    }

    public void setPassed(boolean passed) {
        this.passed = passed;
    }

    public String getAction() {
        return this.action;
    }

    public void setAction(String action) {
        this.action = action;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        QualityCheck entity = (QualityCheck) o;
        return Objects.equals(checkId, entity.checkId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(checkId);
    }
}