package de.smart.city.manufacturing;

import java.time.LocalDate;
import java.util.Objects;

public class Machine {
    protected static MachineDelegate delegate;
    protected String machineId;
    protected MachineStatus status;
    protected MaintenanceSchedule maintenance;
    protected String manufacturer;
    protected String model;
    protected LocalDate installationDate;
    protected double powerConsumption;



    public String getMachineId() {
        return this.machineId;
    }

    public void setMachineId(String machineId) {
        this.machineId = machineId;
    }

    public MachineStatus getStatus() {
        return this.status;
    }

    public void setStatus(MachineStatus status) {
        this.status = status;
    }

    public MaintenanceSchedule getMaintenance() {
        return this.maintenance;
    }

    public void setMaintenance(MaintenanceSchedule maintenance) {
        this.maintenance = maintenance;
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

    public LocalDate getInstallationDate() {
        return this.installationDate;
    }

    public void setInstallationDate(LocalDate installationDate) {
        this.installationDate = installationDate;
    }

    public double getPowerConsumption() {
        return this.powerConsumption;
    }

    public void setPowerConsumption(double powerConsumption) {
        this.powerConsumption = powerConsumption;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Machine entity = (Machine) o;
        return Objects.equals(machineId, entity.machineId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(machineId);
    }
}