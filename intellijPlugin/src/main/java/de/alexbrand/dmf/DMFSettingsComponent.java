package de.alexbrand.dmf;

import com.intellij.ui.components.JBLabel;
import com.intellij.ui.components.JBTextField;
import com.intellij.util.ui.FormBuilder;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;

public class DMFSettingsComponent {
    private final JPanel myMainPanel;
    private final JBTextField lspDirPathField = new JBTextField();

    public DMFSettingsComponent() {
        myMainPanel = FormBuilder.createFormBuilder()
                .addLabeledComponent(new JBLabel("Directory for DMF-LSP Installations:"), lspDirPathField, 1, false)
                .addComponentFillVertically(new JPanel(), 0)
                .getPanel();
    }

    public JPanel getPanel() {
        return myMainPanel;
    }

    public JComponent getPreferredFocusedComponent() {
        return lspDirPathField;
    }

    @NotNull
    public String getLspDirPath() {
        return lspDirPathField.getText();
    }

    public void setUserNameText(@NotNull String newText) {
        lspDirPathField.setText(newText);
    }

}
