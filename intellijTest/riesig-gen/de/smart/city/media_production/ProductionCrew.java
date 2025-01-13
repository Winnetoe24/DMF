package de.smart.city.media_production;
import java.util.Objects;

public class ProductionCrew {
    protected static ProductionCrewDelegate delegate;
    protected String crewId;
    protected FilmPermit permit;
    protected String productionCompany;
    protected String contactPerson;



    public String getCrewId() {
        return this.crewId;
    }

    public void setCrewId(String crewId) {
        this.crewId = crewId;
    }

    public FilmPermit getPermit() {
        return this.permit;
    }

    public void setPermit(FilmPermit permit) {
        this.permit = permit;
    }

    public String getProductionCompany() {
        return this.productionCompany;
    }

    public void setProductionCompany(String productionCompany) {
        this.productionCompany = productionCompany;
    }

    public String getContactPerson() {
        return this.contactPerson;
    }

    public void setContactPerson(String contactPerson) {
        this.contactPerson = contactPerson;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        ProductionCrew entity = (ProductionCrew) o;
        return Objects.equals(crewId, entity.crewId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(crewId);
    }
}