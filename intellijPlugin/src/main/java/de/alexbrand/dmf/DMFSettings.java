package de.alexbrand.dmf;

import com.intellij.openapi.application.ApplicationManager;
import com.intellij.openapi.components.PersistentStateComponent;
import com.intellij.openapi.components.State;
import com.intellij.openapi.components.Storage;
import com.intellij.openapi.components.StoragePathMacros;
import org.jetbrains.annotations.NonNls;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

@State(
        name = "de.alexbrand.DMFSettings",
        storages = @Storage("dmf.xml")
)
public class DMFSettings  implements PersistentStateComponent<DMFSettings.State> {

    static DMFSettings getInstance() {
        return ApplicationManager.getApplication()
                .getService(DMFSettings.class);
    }

    static class State {
        @NonNls
        public String lspDirPath = "./.dmf";
    }
    private State myState = new State();

    @Override
    public @Nullable DMFSettings.State getState() {
        return myState;
    }

    @Override
    public void loadState(@NotNull State state) {
        myState = state;

    }

}
