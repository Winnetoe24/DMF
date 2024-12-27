package de.library.management.facilities;

/**
 * Ausstattungsstatus
 **/
public enum EquipmentStatus {
    OPERATIONAL(),
    MAINTENANCE(),
    OUT_OF_ORDER(),
    RESERVED();


    EquipmentStatus(){
        
    }
}