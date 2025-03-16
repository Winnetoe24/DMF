package de.alexbrand.dmf;

import com.intellij.execution.configurations.GeneralCommandLine;
import com.redhat.devtools.lsp4ij.server.OSProcessStreamConnectionProvider;

public class DMFLanguageServer extends OSProcessStreamConnectionProvider {
    public DMFLanguageServer() {
        GeneralCommandLine commandLine = new GeneralCommandLine("/home/alexander/LocalNAS/Bachelorarbeit/DMF/lsp/lsp", "--disabledLog");
        super.setCommandLine(commandLine);
    }
}
