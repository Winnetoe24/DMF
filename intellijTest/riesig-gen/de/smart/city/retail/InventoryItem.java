package de.smart.city.retail;
import java.util.Objects;

public class InventoryItem {
    protected static InventoryItemDelegate delegate;
    protected String itemId;
    protected RetailStore store;
    protected String name;
    protected int stockLevel;
    protected double price;
    protected boolean isDiscounted;



    public String getItemId() {
        return this.itemId;
    }

    public void setItemId(String itemId) {
        this.itemId = itemId;
    }

    public RetailStore getStore() {
        return this.store;
    }

    public void setStore(RetailStore store) {
        this.store = store;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getStockLevel() {
        return this.stockLevel;
    }

    public void setStockLevel(int stockLevel) {
        this.stockLevel = stockLevel;
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public boolean getIsDiscounted() {
        return this.isDiscounted;
    }

    public void setIsDiscounted(boolean isDiscounted) {
        this.isDiscounted = isDiscounted;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        InventoryItem entity = (InventoryItem) o;
        return Objects.equals(itemId, entity.itemId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(itemId);
    }
}