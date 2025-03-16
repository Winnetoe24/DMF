package de.alexbrand.dmf;

import com.intellij.openapi.options.Configurable;
import com.intellij.openapi.options.ConfigurationException;
import com.intellij.openapi.util.NlsContexts;
import com.redhat.devtools.lsp4ij.LanguageServerManager;
import org.jetbrains.annotations.Nullable;

import javax.swing.*;
import java.util.Objects;

public class DMFSettingsConfigurable implements Configurable {
    private DMFSettingsComponent mySettingsComponent;
    @Override
    public @NlsContexts.ConfigurableName String getDisplayName() {
        return "DMF: Domain Modelling Framework";
    }

    @Override
    public @Nullable JComponent getPreferredFocusedComponent() {
        return mySettingsComponent.getPreferredFocusedComponent();
    }

    @Override
    public @Nullable JComponent createComponent() {
        mySettingsComponent = new DMFSettingsComponent();
        return mySettingsComponent.getPanel();
    }

    @Override
    public boolean isModified() {
        DMFSettings.State state = Objects.requireNonNull(DMFSettings.getInstance().getState());
        return !mySettingsComponent.getLspDirPath().equals(state.lspDirPath);
    }

    @Override
    public void apply() throws ConfigurationException {
        DMFSettings.State state = Objects.requireNonNull(DMFSettings.getInstance().getState());
        state.lspDirPath = mySettingsComponent.getLspDirPath();
        DMFServerFactory.restartServers();
    }
    @Override
    public void disposeUIResources() {
        mySettingsComponent = null;
    }

}
