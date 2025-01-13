package de.smart.city.fintech;

/**
 * Delegate von AuthenticationSystem * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AuthenticationSystemDelegate {
    static {
        AuthenticationSystem.delegate = new AuthenticationSystemDelegate();
    }
    public void revokeAccess(AuthenticationSystem caller, String userId){
        ;
    }

    public boolean encrypt(AuthenticationSystem caller){
        return false;
    }

    public boolean decrypt(AuthenticationSystem caller){
        return false;
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(AuthenticationSystem caller){
        return "";
    }

    public boolean hasPermission(AuthenticationSystem caller, String role){
        return false;
    }
}