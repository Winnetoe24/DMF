package de.library.management.verification;

import java.time.LocalDate;
import de.library.management.users.User;
import java.util.Objects;

public class StudentId {
    protected static StudentIdDelegate delegate;
    protected User user;
    protected StudentIdType type;
    protected University university;
    protected VerificationDocument document;
    protected VerificationStatus status;
    protected String studentNumber;
    protected String faculty;
    protected int semester;
    protected LocalDate validUntil;



    public User getUser() {
        return this.user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public StudentIdType getType() {
        return this.type;
    }

    public void setType(StudentIdType type) {
        this.type = type;
    }

    public University getUniversity() {
        return this.university;
    }

    public void setUniversity(University university) {
        this.university = university;
    }

    public VerificationDocument getDocument() {
        return this.document;
    }

    public void setDocument(VerificationDocument document) {
        this.document = document;
    }

    public VerificationStatus getStatus() {
        return this.status;
    }

    public void setStatus(VerificationStatus status) {
        this.status = status;
    }

    public String getStudentNumber() {
        return this.studentNumber;
    }

    public void setStudentNumber(String studentNumber) {
        this.studentNumber = studentNumber;
    }

    public String getFaculty() {
        return this.faculty;
    }

    public void setFaculty(String faculty) {
        this.faculty = faculty;
    }

    public int getSemester() {
        return this.semester;
    }

    public void setSemester(int semester) {
        this.semester = semester;
    }

    public LocalDate getValidUntil() {
        return this.validUntil;
    }

    public void setValidUntil(LocalDate validUntil) {
        this.validUntil = validUntil;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        StudentId entity = (StudentId) o;
        return Objects.equals(user, entity.user)  && Objects.equals(studentNumber, entity.studentNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(user, studentNumber);
    }
}