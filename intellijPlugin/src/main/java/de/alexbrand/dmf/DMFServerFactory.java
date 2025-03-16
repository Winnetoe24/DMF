package de.alexbrand.dmf;

import com.intellij.openapi.project.Project;
import com.redhat.devtools.lsp4ij.LanguageServerFactory;
import com.redhat.devtools.lsp4ij.LanguageServerManager;
import com.redhat.devtools.lsp4ij.client.LanguageClientImpl;
import com.redhat.devtools.lsp4ij.server.StreamConnectionProvider;
import org.eclipse.lsp4j.services.LanguageServer;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class DMFServerFactory implements LanguageServerFactory {

    private static Set<Project> projects = new HashSet<>();

    @Override
    public @NotNull StreamConnectionProvider createConnectionProvider(@NotNull Project project) {
        try {
            projects.add(project);
            return new DMFLanguageServer();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override // If you need to provide client specific features
    public @NotNull LanguageClientImpl createLanguageClient(@NotNull Project project) {
        return new DMFLanguageClient(project);
    }

    @Override // If you need to expose a custom server API
    public @NotNull Class<? extends LanguageServer> getServerInterface() {
        return DMFServerAPI.class;
    }

    public static void restartServers() {
        HashSet<Project> curProjects = new HashSet<>(projects);
        projects.clear();
        for (Project project : curProjects) {
            LanguageServerManager.getInstance(project).stop("dmf-server");
            LanguageServerManager.getInstance(project).start("dmf-server");
        }

    }
}