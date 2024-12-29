package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.employees.Employee;
import java.util.Objects;

public class VerificationLog {
    protected StudentId studentId;
    protected Employee verifiedBy;
    protected LocalDate verificationDate;
    protected String verificationMethod;
    protected String notes;
    protected boolean isSuccessful;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VerificationLog entity = (VerificationLog) o;
        return Objects.equals(studentId, entity.studentId)  && Objects.equals(verifiedBy, entity.verifiedBy)  && Objects.equals(verificationDate, entity.verificationDate)  && Objects.equals(verificationMethod, entity.verificationMethod)  && Objects.equals(notes, entity.notes)  && Objects.equals(isSuccessful, entity.isSuccessful) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(studentId, verifiedBy, verificationDate, verificationMethod, notes, isSuccessful);
    }
}