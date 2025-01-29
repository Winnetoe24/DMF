package de.smart.city.manufacturing;

/**
 **/
public enum MachineStatus {
    RUNNING(),
    IDLE(),
    MAINTENANCE(),
    ERROR(),
    OFFLINE(),
    CALIBRATING(),
    WARMING_UP(),
    COOLING_DOWN(),
    EMERGENCY_STOP(),
    STANDBY();


    MachineStatus(){
        
    }
}