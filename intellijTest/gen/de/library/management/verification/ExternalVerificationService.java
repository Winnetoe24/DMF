package de.library.management.verification;

public interface  ExternalVerificationService {
    public boolean verifyWithUniversity(de.library.management.verification.StudentId studentId);
    public boolean checkEnrollmentStatus(de.library.management.verification.StudentId studentId);
    public void notifyStatusChange(de.library.management.verification.StudentId studentId, de.library.management.verification.VerificationStatus newStatus);

}