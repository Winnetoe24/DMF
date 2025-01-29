package de.smart.city.analytics;

import java.time.LocalDateTime;
import java.util.Objects;

public class DataPoint {
    protected static DataPointDelegate delegate;
    protected String dataId;
    protected MetricType type;
    protected double value;
    protected LocalDateTime timestamp;
    protected String source;
    protected boolean isVerified;



    public String getDataId() {
        return this.dataId;
    }

    public void setDataId(String dataId) {
        this.dataId = dataId;
    }

    public MetricType getType() {
        return this.type;
    }

    public void setType(MetricType type) {
        this.type = type;
    }

    public double getValue() {
        return this.value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public LocalDateTime getTimestamp() {
        return this.timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public String getSource() {
        return this.source;
    }

    public void setSource(String source) {
        this.source = source;
    }

    public boolean getIsVerified() {
        return this.isVerified;
    }

    public void setIsVerified(boolean isVerified) {
        this.isVerified = isVerified;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        DataPoint entity = (DataPoint) o;
        return Objects.equals(dataId, entity.dataId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(dataId);
    }
}