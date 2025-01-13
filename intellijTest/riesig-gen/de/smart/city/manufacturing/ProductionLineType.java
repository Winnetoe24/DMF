package de.smart.city.manufacturing;

/**
 **/
public enum ProductionLineType {
    ASSEMBLY(),
    PACKAGING(),
    TESTING(),
    MACHINING(),
    FINISHING(),
    CHEMICAL_PROCESSING(),
    FOOD_PROCESSING(),
    ELECTRONICS(),
    AUTOMOTIVE(),
    PHARMACEUTICAL();


    ProductionLineType(){
        
    }
}