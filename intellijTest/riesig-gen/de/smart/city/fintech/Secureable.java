package de.smart.city.fintech;

public interface Secureable {
    public boolean encrypt();
    public boolean decrypt();
    /**
     * TODO []
     **/
    public String getAccessRoles();
    public boolean hasPermission(String role);
    public void revokeAccess(String userId);

}