package de.smart.city.wastewater;

import java.time.LocalDateTime;
import java.util.Objects;

public class QualityTest {
    protected static QualityTestDelegate delegate;
    protected String testId;
    protected WaterQualityMetric metric;
    protected double value;
    protected LocalDateTime timestamp;
    protected boolean meetsStandard;
    protected String analyst;



    public String getTestId() {
        return this.testId;
    }

    public void setTestId(String testId) {
        this.testId = testId;
    }

    public WaterQualityMetric getMetric() {
        return this.metric;
    }

    public void setMetric(WaterQualityMetric metric) {
        this.metric = metric;
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

    public boolean getMeetsStandard() {
        return this.meetsStandard;
    }

    public void setMeetsStandard(boolean meetsStandard) {
        this.meetsStandard = meetsStandard;
    }

    public String getAnalyst() {
        return this.analyst;
    }

    public void setAnalyst(String analyst) {
        this.analyst = analyst;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        QualityTest entity = (QualityTest) o;
        return Objects.equals(testId, entity.testId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(testId);
    }
}