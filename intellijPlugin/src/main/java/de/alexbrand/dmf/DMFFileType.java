package de.alexbrand.dmf;

import com.intellij.lang.Language;
import com.intellij.openapi.fileTypes.LanguageFileType;
import com.intellij.openapi.util.NlsContexts;
import com.intellij.openapi.util.NlsSafe;
import com.intellij.ui.IconManager;
import com.intellij.ui.PlatformIcons;
import org.jetbrains.annotations.NonNls;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;

public class DMFFileType extends LanguageFileType {
    public static final DMFFileType INSTANCE = new DMFFileType();
    protected DMFFileType() {
        super(DMFLanguage.INSTANCE);
    }

    @Override
    public @NonNls @NotNull String getName() {
        return "DMF";
    }

    @Override
    public @NlsContexts.Label @NotNull String getDescription() {
        return "A domain modelling framework model.";
    }

    @Override
    public @NlsSafe @NotNull String getDefaultExtension() {
        return "dmf";
    }

    @Override
    public Icon getIcon() {
        return  IconManager.getInstance().getPlatformIcon(PlatformIcons.PropertiesFileType);
    }
}
