package de.alexbrand.dmf;

import com.intellij.lang.Language;
import org.jetbrains.annotations.NonNls;
import org.jetbrains.annotations.NotNull;

public class DMFLanguage extends Language {
    public static final DMFLanguage INSTANCE = new DMFLanguage();
    protected DMFLanguage() {
        super("dmf");
    }
}
