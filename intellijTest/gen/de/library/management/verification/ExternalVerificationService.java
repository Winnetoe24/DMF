package de.library.management.verification;

public interface ExternalVerificationService {
    public boolean verifyWithUniversity(StudentId studentId);
    public boolean checkEnrollmentStatus(StudentId studentId);
    public void notifyStatusChange(StudentId studentId, VerificationStatus newStatus);

}