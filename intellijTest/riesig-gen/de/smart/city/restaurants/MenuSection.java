package de.smart.city.restaurants;
import java.util.Objects;

/**
 **/
public class MenuSection {
    protected static MenuSectionDelegate delegate;
    protected String name;
    /**
     * TODO []
     **/
    protected String items;
    /**
     * TODO []
     **/
    protected double prices;
    protected boolean isSpecial;

    public double getAveragePrice(){
        return delegate.getAveragePrice(this);
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }
    /**
     * TODO []
     **/
    public String getItems() {
        return this.items;
    }

    /**
     * TODO []
     **/
    public void setItems(String items) {
        this.items = items;
    }

    /**
     * TODO []
     **/
    public double getPrices() {
        return this.prices;
    }

    /**
     * TODO []
     **/
    public void setPrices(double prices) {
        this.prices = prices;
    }

    public boolean getIsSpecial() {
        return this.isSpecial;
    }

    public void setIsSpecial(boolean isSpecial) {
        this.isSpecial = isSpecial;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        MenuSection entity = (MenuSection) o;
        return Objects.equals(name, entity.name)  && Objects.equals(items, entity.items)  && Objects.equals(prices, entity.prices)  && Objects.equals(isSpecial, entity.isSpecial) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, items, prices, isSpecial);
    }
}