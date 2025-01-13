package de.smart.city.analytics;

import java.time.LocalDateTime;
import java.util.Objects;

/**
 **/
public class AnalyticsReport {
    protected static AnalyticsReportDelegate delegate;
    protected String reportId;
    protected MetricType type;
    protected LocalDateTime generationTime;
    protected String format;
    protected boolean isPublic;

    public void generatePDF(){
        delegate.generatePDF(this);
    }

    public String getReportId() {
        return this.reportId;
    }

    public void setReportId(String reportId) {
        this.reportId = reportId;
    }
    public MetricType getType() {
        return this.type;
    }

    public void setType(MetricType type) {
        this.type = type;
    }

    public LocalDateTime getGenerationTime() {
        return this.generationTime;
    }

    public void setGenerationTime(LocalDateTime generationTime) {
        this.generationTime = generationTime;
    }

    public String getFormat() {
        return this.format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public boolean getIsPublic() {
        return this.isPublic;
    }

    public void setIsPublic(boolean isPublic) {
        this.isPublic = isPublic;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AnalyticsReport entity = (AnalyticsReport) o;
        return Objects.equals(format, entity.format)  && Objects.equals(isPublic, entity.isPublic)  && Objects.equals(type, entity.type)  && Objects.equals(reportId, entity.reportId)  && Objects.equals(generationTime, entity.generationTime) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(format, isPublic, type, reportId, generationTime);
    }
}