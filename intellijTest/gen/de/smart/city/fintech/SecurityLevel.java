package de.smart.city.fintech;

/**
 **/
public enum SecurityLevel {
    BASIC(1, "TLS"),
    ENHANCED(2, "TLS+2FA"),
    ADVANCED(3, "TLS+2FA+Biometric"),
    MAXIMUM(4, "TLS+2FA+Biometric+Hardware");

    protected int clearance;
    protected String protocol;

    SecurityLevel(int clearance, String protocol){
        
        this.clearance = clearance;
        this.protocol = protocol;
    }
}