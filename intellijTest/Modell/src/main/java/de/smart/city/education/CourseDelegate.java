package de.smart.city.education;

/**
 * Delegate von Course * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class CourseDelegate {
    static {
        Course.delegate = new CourseDelegate();
    }

}