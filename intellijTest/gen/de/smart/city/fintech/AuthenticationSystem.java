package de.smart.city.fintech;
import java.util.Objects;

public class AuthenticationSystem implements Secureable {
    protected static AuthenticationSystemDelegate delegate;
    protected String systemId;
    protected SecurityLevel level;
    protected boolean multiFactorEnabled;

    public boolean hasPermission(String role){
        return delegate.hasPermission(this, role);
    }

    public void revokeAccess(String userId){
        delegate.revokeAccess(this, userId);
    }

    public boolean encrypt(){
        return delegate.encrypt(this);
    }

    public boolean decrypt(){
        return delegate.decrypt(this);
    }

    /**
     * TODO []
     **/
    public String getAccessRoles(){
        return delegate.getAccessRoles(this);
    }

    public String getSystemId() {
        return this.systemId;
    }

    public void setSystemId(String systemId) {
        this.systemId = systemId;
    }

    public SecurityLevel getLevel() {
        return this.level;
    }

    public void setLevel(SecurityLevel level) {
        this.level = level;
    }

    public boolean getMultiFactorEnabled() {
        return this.multiFactorEnabled;
    }

    public void setMultiFactorEnabled(boolean multiFactorEnabled) {
        this.multiFactorEnabled = multiFactorEnabled;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AuthenticationSystem entity = (AuthenticationSystem) o;
        return Objects.equals(systemId, entity.systemId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(systemId);
    }
}