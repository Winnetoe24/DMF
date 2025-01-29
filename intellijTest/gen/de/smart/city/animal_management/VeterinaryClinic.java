package de.smart.city.animal_management;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class VeterinaryClinic extends Asset {
    protected static VeterinaryClinicDelegate delegate;
    protected String clinicName;
    protected boolean emergencyTwentyFourHour;
    protected int capacity;
    protected boolean hasLaboratory;



    public String getClinicName() {
        return this.clinicName;
    }

    public void setClinicName(String clinicName) {
        this.clinicName = clinicName;
    }

    public boolean getEmergencyTwentyFourHour() {
        return this.emergencyTwentyFourHour;
    }

    public void setEmergencyTwentyFourHour(boolean emergencyTwentyFourHour) {
        this.emergencyTwentyFourHour = emergencyTwentyFourHour;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public boolean getHasLaboratory() {
        return this.hasLaboratory;
    }

    public void setHasLaboratory(boolean hasLaboratory) {
        this.hasLaboratory = hasLaboratory;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VeterinaryClinic entity = (VeterinaryClinic) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}