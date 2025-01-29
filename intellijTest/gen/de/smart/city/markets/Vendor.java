package de.smart.city.markets;

import java.time.LocalDate;
import java.util.Objects;

public class Vendor {
    protected static VendorDelegate delegate;
    protected String vendorId;
    protected VendorCategory category;
    protected Market market;
    protected String products;
    protected boolean isRegistered;
    protected LocalDate licenseExpiry;



    public String getVendorId() {
        return this.vendorId;
    }

    public void setVendorId(String vendorId) {
        this.vendorId = vendorId;
    }

    public VendorCategory getCategory() {
        return this.category;
    }

    public void setCategory(VendorCategory category) {
        this.category = category;
    }

    public Market getMarket() {
        return this.market;
    }

    public void setMarket(Market market) {
        this.market = market;
    }

    public String getProducts() {
        return this.products;
    }

    public void setProducts(String products) {
        this.products = products;
    }

    public boolean getIsRegistered() {
        return this.isRegistered;
    }

    public void setIsRegistered(boolean isRegistered) {
        this.isRegistered = isRegistered;
    }

    public LocalDate getLicenseExpiry() {
        return this.licenseExpiry;
    }

    public void setLicenseExpiry(LocalDate licenseExpiry) {
        this.licenseExpiry = licenseExpiry;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Vendor entity = (Vendor) o;
        return Objects.equals(vendorId, entity.vendorId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(vendorId);
    }
}