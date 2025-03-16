package de.alexbrand.dmf;

import com.intellij.execution.configurations.GeneralCommandLine;
import com.redhat.devtools.lsp4ij.server.OSProcessStreamConnectionProvider;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;

public class DMFLanguageServer extends OSProcessStreamConnectionProvider {
    public DMFLanguageServer() throws IOException {
        String dmfLspLocation = System.getenv("DMF_LSP");
        if (dmfLspLocation == null) {
            dmfLspLocation = "./.dmf/lsp/";
        }
        File dmfLspDir = new File(dmfLspLocation);
        if (!dmfLspDir.exists()) {
            dmfLspDir.mkdirs();
        }
        File lspFile = new File(dmfLspDir, getFileName());
        if (!lspFile.exists()) {
            InputStream resource = this.getClass().getResourceAsStream("/" + getFileName());
            Files.copy(resource, lspFile.toPath());
        }
        GeneralCommandLine commandLine = new GeneralCommandLine(lspFile.getAbsolutePath(), "--disabledLog");
        super.setCommandLine(commandLine);
    }

    private String getFileName() {
        switch (OperatingSystem.OS) {
            case LINUX:
                return "lsp";
            case WINDOWS:
                return "lsp.exe";
        }
        throw new RuntimeException("Unsupported OS: " + System.getProperty("os.name"));
    }
}
