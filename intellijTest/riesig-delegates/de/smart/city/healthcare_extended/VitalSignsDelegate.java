package de.smart.city.healthcare_extended;

/**
 * Delegate von VitalSigns * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class VitalSignsDelegate {
    static {
        VitalSigns.delegate = new VitalSignsDelegate();
    }
    public String getStatus(VitalSigns caller){
        return "";
    }

    public boolean isNormal(VitalSigns caller){
        return false;
    }
}