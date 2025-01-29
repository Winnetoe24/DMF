package de.library.management.users;
import java.util.Objects;

/**
 * Adressinformationen
 **/
public class Address {
    protected static AddressDelegate delegate;
    protected String street;
    protected String houseNumber;
    protected String postalCode;
    protected String city;
    protected String country;



    public String getStreet() {
        return this.street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getHouseNumber() {
        return this.houseNumber;
    }

    public void setHouseNumber(String houseNumber) {
        this.houseNumber = houseNumber;
    }

    public String getPostalCode() {
        return this.postalCode;
    }

    public void setPostalCode(String postalCode) {
        this.postalCode = postalCode;
    }

    public String getCity() {
        return this.city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCountry() {
        return this.country;
    }

    public void setCountry(String country) {
        this.country = country;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Address entity = (Address) o;
        return Objects.equals(postalCode, entity.postalCode)  && Objects.equals(city, entity.city)  && Objects.equals(country, entity.country)  && Objects.equals(street, entity.street)  && Objects.equals(houseNumber, entity.houseNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(postalCode, city, country, street, houseNumber);
    }
}