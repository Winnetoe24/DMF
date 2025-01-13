package de.smart.city.animal_management;

import java.time.LocalDate;
import java.util.Objects;

public class PetLicense {
    protected static PetLicenseDelegate delegate;
    protected String licenseId;
    protected Pet pet;
    protected LicenseStatus status;
    protected LocalDate issueDate;
    protected LocalDate expiryDate;
    protected double fee;
    protected boolean rabiesVaccinated;



    public String getLicenseId() {
        return this.licenseId;
    }

    public void setLicenseId(String licenseId) {
        this.licenseId = licenseId;
    }

    public Pet getPet() {
        return this.pet;
    }

    public void setPet(Pet pet) {
        this.pet = pet;
    }

    public LicenseStatus getStatus() {
        return this.status;
    }

    public void setStatus(LicenseStatus status) {
        this.status = status;
    }

    public LocalDate getIssueDate() {
        return this.issueDate;
    }

    public void setIssueDate(LocalDate issueDate) {
        this.issueDate = issueDate;
    }

    public LocalDate getExpiryDate() {
        return this.expiryDate;
    }

    public void setExpiryDate(LocalDate expiryDate) {
        this.expiryDate = expiryDate;
    }

    public double getFee() {
        return this.fee;
    }

    public void setFee(double fee) {
        this.fee = fee;
    }

    public boolean getRabiesVaccinated() {
        return this.rabiesVaccinated;
    }

    public void setRabiesVaccinated(boolean rabiesVaccinated) {
        this.rabiesVaccinated = rabiesVaccinated;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PetLicense entity = (PetLicense) o;
        return Objects.equals(licenseId, entity.licenseId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(licenseId);
    }
}