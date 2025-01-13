package de.smart.city.education;
import java.util.Objects;

public class Course {
    protected static CourseDelegate delegate;
    protected String courseId;
    protected CourseLevel level;
    protected String title;
    protected int credits;
    protected int maxEnrollment;
    protected boolean isOnline;



    public String getCourseId() {
        return this.courseId;
    }

    public void setCourseId(String courseId) {
        this.courseId = courseId;
    }

    public CourseLevel getLevel() {
        return this.level;
    }

    public void setLevel(CourseLevel level) {
        this.level = level;
    }

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getCredits() {
        return this.credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

    public int getMaxEnrollment() {
        return this.maxEnrollment;
    }

    public void setMaxEnrollment(int maxEnrollment) {
        this.maxEnrollment = maxEnrollment;
    }

    public boolean getIsOnline() {
        return this.isOnline;
    }

    public void setIsOnline(boolean isOnline) {
        this.isOnline = isOnline;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Course entity = (Course) o;
        return Objects.equals(courseId, entity.courseId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(courseId);
    }
}