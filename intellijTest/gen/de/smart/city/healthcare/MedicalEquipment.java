package de.smart.city.healthcare;

import java.time.LocalDate;
import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class MedicalEquipment extends Asset {
    protected static MedicalEquipmentDelegate delegate;
    protected String equipmentType;
    protected String manufacturer;
    protected LocalDate warrantyExpiry;
    protected int hoursInUse;
    protected boolean requiresCalibration;



    public String getEquipmentType() {
        return this.equipmentType;
    }

    public void setEquipmentType(String equipmentType) {
        this.equipmentType = equipmentType;
    }

    public String getManufacturer() {
        return this.manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public LocalDate getWarrantyExpiry() {
        return this.warrantyExpiry;
    }

    public void setWarrantyExpiry(LocalDate warrantyExpiry) {
        this.warrantyExpiry = warrantyExpiry;
    }

    public int getHoursInUse() {
        return this.hoursInUse;
    }

    public void setHoursInUse(int hoursInUse) {
        this.hoursInUse = hoursInUse;
    }

    public boolean getRequiresCalibration() {
        return this.requiresCalibration;
    }

    public void setRequiresCalibration(boolean requiresCalibration) {
        this.requiresCalibration = requiresCalibration;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MedicalEquipment entity = (MedicalEquipment) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}