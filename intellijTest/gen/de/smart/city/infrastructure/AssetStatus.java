package de.smart.city.infrastructure;

/**
 **/
public enum AssetStatus {
    OPERATIONAL(),
    MAINTENANCE_REQUIRED(),
    UNDER_REPAIR(),
    DECOMMISSIONED(),
    CRITICAL();


    AssetStatus(){
        
    }
}