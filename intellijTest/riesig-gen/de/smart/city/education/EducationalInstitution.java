package de.smart.city.education;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class EducationalInstitution extends Asset {
    protected static EducationalInstitutionDelegate delegate;
    protected InstitutionType type;
    protected int studentCapacity;
    protected int staffCount;
    protected boolean isPublic;
    protected String accreditationStatus;



    public InstitutionType getType() {
        return this.type;
    }

    public void setType(InstitutionType type) {
        this.type = type;
    }

    public int getStudentCapacity() {
        return this.studentCapacity;
    }

    public void setStudentCapacity(int studentCapacity) {
        this.studentCapacity = studentCapacity;
    }

    public int getStaffCount() {
        return this.staffCount;
    }

    public void setStaffCount(int staffCount) {
        this.staffCount = staffCount;
    }

    public boolean getIsPublic() {
        return this.isPublic;
    }

    public void setIsPublic(boolean isPublic) {
        this.isPublic = isPublic;
    }

    public String getAccreditationStatus() {
        return this.accreditationStatus;
    }

    public void setAccreditationStatus(String accreditationStatus) {
        this.accreditationStatus = accreditationStatus;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        EducationalInstitution entity = (EducationalInstitution) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}