package de.smart.city.signage;

import java.time.LocalDateTime;
import java.util.Objects;

public class SignContent {
    protected static SignContentDelegate delegate;
    protected String contentId;
    protected DigitalSign sign;
    protected String content;
    protected LocalDateTime startDisplay;
    protected LocalDateTime endDisplay;
    protected int priority;



    public String getContentId() {
        return this.contentId;
    }

    public void setContentId(String contentId) {
        this.contentId = contentId;
    }

    public DigitalSign getSign() {
        return this.sign;
    }

    public void setSign(DigitalSign sign) {
        this.sign = sign;
    }

    public String getContent() {
        return this.content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public LocalDateTime getStartDisplay() {
        return this.startDisplay;
    }

    public void setStartDisplay(LocalDateTime startDisplay) {
        this.startDisplay = startDisplay;
    }

    public LocalDateTime getEndDisplay() {
        return this.endDisplay;
    }

    public void setEndDisplay(LocalDateTime endDisplay) {
        this.endDisplay = endDisplay;
    }

    public int getPriority() {
        return this.priority;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        SignContent entity = (SignContent) o;
        return Objects.equals(contentId, entity.contentId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(contentId);
    }
}