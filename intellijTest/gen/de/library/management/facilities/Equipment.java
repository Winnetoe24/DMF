package de.library.management.facilities;

import java.time.LocalDate;
import java.util.Objects;

public class Equipment {
    protected static EquipmentDelegate delegate;
    protected Room room;
    protected EquipmentStatus status;
    protected String name;
    protected String serialNumber;
    protected LocalDate purchaseDate;
    protected LocalDate lastMaintenance;
    protected String manufacturer;



    public Room getRoom() {
        return this.room;
    }

    public void setRoom(Room room) {
        this.room = room;
    }

    public EquipmentStatus getStatus() {
        return this.status;
    }

    public void setStatus(EquipmentStatus status) {
        this.status = status;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
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

    public LocalDate getLastMaintenance() {
        return this.lastMaintenance;
    }

    public void setLastMaintenance(LocalDate lastMaintenance) {
        this.lastMaintenance = lastMaintenance;
    }

    public String getManufacturer() {
        return this.manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Equipment entity = (Equipment) o;
        return Objects.equals(serialNumber, entity.serialNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(serialNumber);
    }
}