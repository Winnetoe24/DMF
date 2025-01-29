package de.smart.city.research_facilities;

import java.time.LocalDateTime;
import de.smart.city.infrastructure.Asset;
import java.time.LocalDate;
import java.util.Objects;

public class ResearchEquipment extends Asset {
    protected static ResearchEquipmentDelegate delegate;
    protected EquipmentSpecification specs;
    protected String manufacturer;
    protected String model;
    protected String serialNumber;
    protected LocalDate purchaseDate;
    protected LocalDate warrantyExpiry;
    protected LocalDateTime lastCalibration;
    protected boolean requiresSpecialTraining;



    public EquipmentSpecification getSpecs() {
        return this.specs;
    }

    public void setSpecs(EquipmentSpecification specs) {
        this.specs = specs;
    }

    public String getManufacturer() {
        return this.manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public String getModel() {
        return this.model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getSerialNumber() {
        return this.serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public LocalDate getPurchaseDate() {
        return this.purchaseDate;
    }

    public void setPurchaseDate(LocalDate purchaseDate) {
        this.purchaseDate = purchaseDate;
    }

    public LocalDate getWarrantyExpiry() {
        return this.warrantyExpiry;
    }

    public void setWarrantyExpiry(LocalDate warrantyExpiry) {
        this.warrantyExpiry = warrantyExpiry;
    }

    public LocalDateTime getLastCalibration() {
        return this.lastCalibration;
    }

    public void setLastCalibration(LocalDateTime lastCalibration) {
        this.lastCalibration = lastCalibration;
    }

    public boolean getRequiresSpecialTraining() {
        return this.requiresSpecialTraining;
    }

    public void setRequiresSpecialTraining(boolean requiresSpecialTraining) {
        this.requiresSpecialTraining = requiresSpecialTraining;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ResearchEquipment entity = (ResearchEquipment) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}