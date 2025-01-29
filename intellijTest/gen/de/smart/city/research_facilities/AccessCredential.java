package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import java.util.Objects;

public class AccessCredential {
    protected static AccessCredentialDelegate delegate;
    protected String credentialId;
    protected Laboratory lab;
    protected DataClassification clearanceLevel;
    protected String holderName;
    protected LocalDateTime validFrom;
    protected LocalDateTime validUntil;
    protected boolean isActive;



    public String getCredentialId() {
        return this.credentialId;
    }

    public void setCredentialId(String credentialId) {
        this.credentialId = credentialId;
    }

    public Laboratory getLab() {
        return this.lab;
    }

    public void setLab(Laboratory lab) {
        this.lab = lab;
    }

    public DataClassification getClearanceLevel() {
        return this.clearanceLevel;
    }

    public void setClearanceLevel(DataClassification clearanceLevel) {
        this.clearanceLevel = clearanceLevel;
    }

    public String getHolderName() {
        return this.holderName;
    }

    public void setHolderName(String holderName) {
        this.holderName = holderName;
    }

    public LocalDateTime getValidFrom() {
        return this.validFrom;
    }

    public void setValidFrom(LocalDateTime validFrom) {
        this.validFrom = validFrom;
    }

    public LocalDateTime getValidUntil() {
        return this.validUntil;
    }

    public void setValidUntil(LocalDateTime validUntil) {
        this.validUntil = validUntil;
    }

    public boolean getIsActive() {
        return this.isActive;
    }

    public void setIsActive(boolean isActive) {
        this.isActive = isActive;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AccessCredential entity = (AccessCredential) o;
        return Objects.equals(credentialId, entity.credentialId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(credentialId);
    }
}