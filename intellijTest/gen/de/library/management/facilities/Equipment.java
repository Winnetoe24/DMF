package de.library.management.facilities;

import java.time.LocalDate;
import java.util.Objects;

public class Equipment {
    protected Room room;
    protected EquipmentStatus status;
    protected String name;
    protected String serialNumber;
    protected LocalDate purchaseDate;
    protected LocalDate lastMaintenance;
    protected String manufacturer;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Equipment entity = (Equipment) o;
        return Objects.equals(room, entity.room)  && Objects.equals(status, entity.status)  && Objects.equals(name, entity.name)  && Objects.equals(serialNumber, entity.serialNumber)  && Objects.equals(purchaseDate, entity.purchaseDate)  && Objects.equals(lastMaintenance, entity.lastMaintenance)  && Objects.equals(manufacturer, entity.manufacturer) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(room, status, name, serialNumber, purchaseDate, lastMaintenance, manufacturer);
    }
}