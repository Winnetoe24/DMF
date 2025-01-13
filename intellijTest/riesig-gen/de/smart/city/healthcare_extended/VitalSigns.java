package de.smart.city.healthcare_extended;
import java.util.Objects;

/**
 **/
public class VitalSigns {
    protected static VitalSignsDelegate delegate;
    protected double temperature;
    protected int heartRate;
    protected int bloodPressureSystolic;
    protected int bloodPressureDiastolic;
    protected int respiratoryRate;
    protected double oxygenSaturation;

    public boolean isNormal(){
        return delegate.isNormal(this);
    }

    public String getStatus(){
        return delegate.getStatus(this);
    }

    public double getTemperature() {
        return this.temperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public int getHeartRate() {
        return this.heartRate;
    }

    public void setHeartRate(int heartRate) {
        this.heartRate = heartRate;
    }
    public int getBloodPressureSystolic() {
        return this.bloodPressureSystolic;
    }

    public void setBloodPressureSystolic(int bloodPressureSystolic) {
        this.bloodPressureSystolic = bloodPressureSystolic;
    }

    public int getBloodPressureDiastolic() {
        return this.bloodPressureDiastolic;
    }

    public void setBloodPressureDiastolic(int bloodPressureDiastolic) {
        this.bloodPressureDiastolic = bloodPressureDiastolic;
    }

    public int getRespiratoryRate() {
        return this.respiratoryRate;
    }

    public void setRespiratoryRate(int respiratoryRate) {
        this.respiratoryRate = respiratoryRate;
    }

    public double getOxygenSaturation() {
        return this.oxygenSaturation;
    }

    public void setOxygenSaturation(double oxygenSaturation) {
        this.oxygenSaturation = oxygenSaturation;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VitalSigns entity = (VitalSigns) o;
        return Objects.equals(temperature, entity.temperature)  && Objects.equals(heartRate, entity.heartRate)  && Objects.equals(bloodPressureSystolic, entity.bloodPressureSystolic)  && Objects.equals(bloodPressureDiastolic, entity.bloodPressureDiastolic)  && Objects.equals(respiratoryRate, entity.respiratoryRate)  && Objects.equals(oxygenSaturation, entity.oxygenSaturation) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(temperature, heartRate, bloodPressureSystolic, bloodPressureDiastolic, respiratoryRate, oxygenSaturation);
    }
}