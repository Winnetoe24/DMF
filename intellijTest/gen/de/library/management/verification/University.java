package de.library.management.verification;
import java.util.Objects;

/**
 * Universitäten
 **/
public class University {
    protected static UniversityDelegate delegate;
    protected String name;
    protected String location;
    protected String verificationEmail;
    protected String apiEndpoint;
    protected boolean hasDirectVerification;



    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLocation() {
        return this.location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getVerificationEmail() {
        return this.verificationEmail;
    }

    public void setVerificationEmail(String verificationEmail) {
        this.verificationEmail = verificationEmail;
    }

    public String getApiEndpoint() {
        return this.apiEndpoint;
    }

    public void setApiEndpoint(String apiEndpoint) {
        this.apiEndpoint = apiEndpoint;
    }

    public boolean getHasDirectVerification() {
        return this.hasDirectVerification;
    }

    public void setHasDirectVerification(boolean hasDirectVerification) {
        this.hasDirectVerification = hasDirectVerification;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        University entity = (University) o;
        return Objects.equals(name, entity.name)  && Objects.equals(location, entity.location)  && Objects.equals(verificationEmail, entity.verificationEmail)  && Objects.equals(apiEndpoint, entity.apiEndpoint)  && Objects.equals(hasDirectVerification, entity.hasDirectVerification) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, location, verificationEmail, apiEndpoint, hasDirectVerification);
    }
}