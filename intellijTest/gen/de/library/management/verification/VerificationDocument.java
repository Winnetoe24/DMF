package de.library.management.verification;

import java.time.LocalDate;
import java.util.Objects;

/**
 * Verifikationsdokument
 **/
public class VerificationDocument {
    protected static VerificationDocumentDelegate delegate;
    protected String documentNumber;
    protected LocalDate issueDate;
    protected LocalDate expiryDate;
    protected String issuingAuthority;
    protected String documentImage;



    public String getDocumentNumber() {
        return this.documentNumber;
    }

    public void setDocumentNumber(String documentNumber) {
        this.documentNumber = documentNumber;
    }

    public LocalDate getIssueDate() {
        return this.issueDate;
    }

    public void setIssueDate(LocalDate issueDate) {
        this.issueDate = issueDate;
    }

    public LocalDate getExpiryDate() {
        return this.expiryDate;
    }

    public void setExpiryDate(LocalDate expiryDate) {
        this.expiryDate = expiryDate;
    }

    public String getIssuingAuthority() {
        return this.issuingAuthority;
    }

    public void setIssuingAuthority(String issuingAuthority) {
        this.issuingAuthority = issuingAuthority;
    }

    public String getDocumentImage() {
        return this.documentImage;
    }

    public void setDocumentImage(String documentImage) {
        this.documentImage = documentImage;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        VerificationDocument entity = (VerificationDocument) o;
        return Objects.equals(issueDate, entity.issueDate)  && Objects.equals(expiryDate, entity.expiryDate)  && Objects.equals(issuingAuthority, entity.issuingAuthority)  && Objects.equals(documentImage, entity.documentImage)  && Objects.equals(documentNumber, entity.documentNumber) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(issueDate, expiryDate, issuingAuthority, documentImage, documentNumber);
    }
}