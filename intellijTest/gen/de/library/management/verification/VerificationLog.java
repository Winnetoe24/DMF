package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.employees.Employee;
import java.util.Objects;

public class VerificationLog {
    protected static VerificationLogDelegate delegate;
    protected StudentId studentId;
    protected Employee verifiedBy;
    protected LocalDate verificationDate;
    protected String verificationMethod;
    protected String notes;
    protected boolean isSuccessful;



    public StudentId getStudentId() {
        return this.studentId;
    }

    public void setStudentId(StudentId studentId) {
        this.studentId = studentId;
    }

    public Employee getVerifiedBy() {
        return this.verifiedBy;
    }

    public void setVerifiedBy(Employee verifiedBy) {
        this.verifiedBy = verifiedBy;
    }

    public LocalDate getVerificationDate() {
        return this.verificationDate;
    }

    public void setVerificationDate(LocalDate verificationDate) {
        this.verificationDate = verificationDate;
    }

    public String getVerificationMethod() {
        return this.verificationMethod;
    }

    public void setVerificationMethod(String verificationMethod) {
        this.verificationMethod = verificationMethod;
    }

    public String getNotes() {
        return this.notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }

    public boolean getIsSuccessful() {
        return this.isSuccessful;
    }

    public void setIsSuccessful(boolean isSuccessful) {
        this.isSuccessful = isSuccessful;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VerificationLog entity = (VerificationLog) o;
        return Objects.equals(studentId, entity.studentId)  && Objects.equals(verificationDate, entity.verificationDate) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(studentId, verificationDate);
    }
}