package de.smart.city.infrastructure;
import java.util.Objects;

/**
 **/
public class GeoLocation {
    protected static GeoLocationDelegate delegate;
    protected double latitude;
    protected double longitude;
    protected double altitude;
    protected String addressString;

    public double calculateDistance(GeoLocation other){
        return delegate.calculateDistance(this, other);
    }

    public double getLatitude() {
        return this.latitude;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }
    public double getLongitude() {
        return this.longitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public double getAltitude() {
        return this.altitude;
    }

    public void setAltitude(double altitude) {
        this.altitude = altitude;
    }

    public String getAddressString() {
        return this.addressString;
    }

    public void setAddressString(String addressString) {
        this.addressString = addressString;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        GeoLocation entity = (GeoLocation) o;
        return Objects.equals(latitude, entity.latitude)  && Objects.equals(longitude, entity.longitude)  && Objects.equals(altitude, entity.altitude)  && Objects.equals(addressString, entity.addressString) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(latitude, longitude, altitude, addressString);
    }
}