package de.alex.brand.klein;

/**
 * Delegate von Ast * Wird nur initial generiert.
 * Methoden müssen implementiert werden.
 **/
public class AstDelegate {
    static {
        Ast.delegate = new AstDelegate();
    }

}