package de.alexbrand.dmf;

import com.intellij.openapi.project.Project;
import com.redhat.devtools.lsp4ij.client.LanguageClientImpl;
import org.eclipse.lsp4j.services.LanguageClient;

public class DMFLanguageClient extends LanguageClientImpl {
    public DMFLanguageClient(Project project) {
        super(project);
    }
}
