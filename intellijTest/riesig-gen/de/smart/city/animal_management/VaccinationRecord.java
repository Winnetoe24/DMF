package de.smart.city.animal_management;

import java.time.LocalDate;
import java.util.Objects;

/**
 **/
public class VaccinationRecord {
    protected static VaccinationRecordDelegate delegate;
    protected String vaccineName;
    protected LocalDate administeredDate;
    protected LocalDate expiryDate;
    protected String veterinarian;

    public boolean isValid(){
        return delegate.isValid(this);
    }

    public String getVaccineName() {
        return this.vaccineName;
    }

    public void setVaccineName(String vaccineName) {
        this.vaccineName = vaccineName;
    }
    public LocalDate getAdministeredDate() {
        return this.administeredDate;
    }

    public void setAdministeredDate(LocalDate administeredDate) {
        this.administeredDate = administeredDate;
    }

    public LocalDate getExpiryDate() {
        return this.expiryDate;
    }

    public void setExpiryDate(LocalDate expiryDate) {
        this.expiryDate = expiryDate;
    }

    public String getVeterinarian() {
        return this.veterinarian;
    }

    public void setVeterinarian(String veterinarian) {
        this.veterinarian = veterinarian;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VaccinationRecord entity = (VaccinationRecord) o;
        return Objects.equals(administeredDate, entity.administeredDate)  && Objects.equals(expiryDate, entity.expiryDate)  && Objects.equals(veterinarian, entity.veterinarian)  && Objects.equals(vaccineName, entity.vaccineName) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(administeredDate, expiryDate, veterinarian, vaccineName);
    }
}