package de.smart.city.animal_management;

import java.time.LocalDate;
import java.util.Objects;

public class Pet {
    protected static PetDelegate delegate;
    protected String petId;
    protected PetType type;
    protected String name;
    protected String breed;
    protected LocalDate birthDate;
    protected LicenseStatus licenseStatus;
    protected String ownerName;
    protected String microchipId;



    public String getPetId() {
        return this.petId;
    }

    public void setPetId(String petId) {
        this.petId = petId;
    }

    public PetType getType() {
        return this.type;
    }

    public void setType(PetType type) {
        this.type = type;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBreed() {
        return this.breed;
    }

    public void setBreed(String breed) {
        this.breed = breed;
    }

    public LocalDate getBirthDate() {
        return this.birthDate;
    }

    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }

    public LicenseStatus getLicenseStatus() {
        return this.licenseStatus;
    }

    public void setLicenseStatus(LicenseStatus licenseStatus) {
        this.licenseStatus = licenseStatus;
    }

    public String getOwnerName() {
        return this.ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public String getMicrochipId() {
        return this.microchipId;
    }

    public void setMicrochipId(String microchipId) {
        this.microchipId = microchipId;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Pet entity = (Pet) o;
        return Objects.equals(petId, entity.petId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(petId);
    }
}