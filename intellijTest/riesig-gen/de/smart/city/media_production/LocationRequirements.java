package de.smart.city.media_production;
import java.util.Objects;

/**
 **/
public class LocationRequirements {
    protected static LocationRequirementsDelegate delegate;
    protected boolean needsPowerSupply;
    protected boolean needsParking;
    protected boolean needsTrafficControl;
    protected boolean needsSecurityPresence;

    public boolean checkCompliance(){
        return delegate.checkCompliance(this);
    }

    public boolean getNeedsPowerSupply() {
        return this.needsPowerSupply;
    }

    public void setNeedsPowerSupply(boolean needsPowerSupply) {
        this.needsPowerSupply = needsPowerSupply;
    }
    public boolean getNeedsParking() {
        return this.needsParking;
    }

    public void setNeedsParking(boolean needsParking) {
        this.needsParking = needsParking;
    }

    public boolean getNeedsTrafficControl() {
        return this.needsTrafficControl;
    }

    public void setNeedsTrafficControl(boolean needsTrafficControl) {
        this.needsTrafficControl = needsTrafficControl;
    }

    public boolean getNeedsSecurityPresence() {
        return this.needsSecurityPresence;
    }

    public void setNeedsSecurityPresence(boolean needsSecurityPresence) {
        this.needsSecurityPresence = needsSecurityPresence;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        LocationRequirements entity = (LocationRequirements) o;
        return Objects.equals(needsPowerSupply, entity.needsPowerSupply)  && Objects.equals(needsParking, entity.needsParking)  && Objects.equals(needsTrafficControl, entity.needsTrafficControl)  && Objects.equals(needsSecurityPresence, entity.needsSecurityPresence) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(needsPowerSupply, needsParking, needsTrafficControl, needsSecurityPresence);
    }
}