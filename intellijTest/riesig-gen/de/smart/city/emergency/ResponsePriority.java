package de.smart.city.emergency;

/**
 **/
public enum ResponsePriority {
    CRITICAL(1),
    HIGH(2),
    MEDIUM(3),
    LOW(4);

    protected int code;

    ResponsePriority(int code){
        
        this.code = code;
    }
}