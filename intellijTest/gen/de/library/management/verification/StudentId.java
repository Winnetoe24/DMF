package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class StudentId {
    protected User user;
    protected StudentIdType type;
    protected University university;
    protected VerificationDocument document;
    protected VerificationStatus status;
    protected String studentNumber;
    protected String faculty;
    protected int semester;
    protected LocalDate validUntil;



    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        StudentId entity = (StudentId) o;
        return Objects.equals(user, entity.user)  && Objects.equals(type, entity.type)  && Objects.equals(university, entity.university)  && Objects.equals(document, entity.document)  && Objects.equals(status, entity.status)  && Objects.equals(studentNumber, entity.studentNumber)  && Objects.equals(faculty, entity.faculty)  && Objects.equals(semester, entity.semester)  && Objects.equals(validUntil, entity.validUntil) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, type, university, document, status, studentNumber, faculty, semester, validUntil);
    }
}