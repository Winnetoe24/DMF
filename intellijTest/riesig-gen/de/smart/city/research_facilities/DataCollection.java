package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import java.util.Objects;

public class DataCollection {
    protected static DataCollectionDelegate delegate;
    protected String datasetId;
    protected Experiment experiment;
    protected DataClassification classification;
    protected LocalDateTime collectionStart;
    protected LocalDateTime collectionEnd;
    protected double sampleSize;
    protected String format;
    protected boolean isBackedUp;



    public String getDatasetId() {
        return this.datasetId;
    }

    public void setDatasetId(String datasetId) {
        this.datasetId = datasetId;
    }

    public Experiment getExperiment() {
        return this.experiment;
    }

    public void setExperiment(Experiment experiment) {
        this.experiment = experiment;
    }

    public DataClassification getClassification() {
        return this.classification;
    }

    public void setClassification(DataClassification classification) {
        this.classification = classification;
    }

    public LocalDateTime getCollectionStart() {
        return this.collectionStart;
    }

    public void setCollectionStart(LocalDateTime collectionStart) {
        this.collectionStart = collectionStart;
    }

    public LocalDateTime getCollectionEnd() {
        return this.collectionEnd;
    }

    public void setCollectionEnd(LocalDateTime collectionEnd) {
        this.collectionEnd = collectionEnd;
    }

    public double getSampleSize() {
        return this.sampleSize;
    }

    public void setSampleSize(double sampleSize) {
        this.sampleSize = sampleSize;
    }

    public String getFormat() {
        return this.format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public boolean getIsBackedUp() {
        return this.isBackedUp;
    }

    public void setIsBackedUp(boolean isBackedUp) {
        this.isBackedUp = isBackedUp;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        DataCollection entity = (DataCollection) o;
        return Objects.equals(datasetId, entity.datasetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(datasetId);
    }
}