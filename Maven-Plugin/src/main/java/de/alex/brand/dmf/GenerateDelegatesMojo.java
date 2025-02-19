package de.alex.brand.dmf;

import org.apache.maven.plugin.MojoExecutionException;
import org.apache.maven.plugin.MojoFailureException;
import org.apache.maven.plugin.logging.Log;
import org.apache.maven.plugins.annotations.LifecyclePhase;
import org.apache.maven.plugins.annotations.Mojo;

import java.io.File;
import java.io.IOException;

@Mojo(name = "generate-delegates", defaultPhase = LifecyclePhase.GENERATE_SOURCES)
public class GenerateDelegatesMojo extends AbstractGeneratorMojo {


    @Override
    protected void generate(Log log, File generatorFile) throws MojoExecutionException, MojoFailureException {
        log.info("Generating Delegates into " + sources);
        ProcessBuilder processBuilder = new ProcessBuilder(generatorFile.getAbsolutePath(),
                "--basePath", sources, "--delegates");

        if (modelPath != null) {
            processBuilder.command().add("--modelFile");
            processBuilder.command().add(modelPath);
        }
        processBuilder.redirectErrorStream(true);

        try {
            Process process = processBuilder.start();
            MojoExecutionException mojoExecutionException = processOutput(log, process);
            int exitCode = process.waitFor();
            log.info("Generator exited with code " + exitCode);
            if (mojoExecutionException != null) {
                throw mojoExecutionException;
            }
            if (exitCode != 0) {
                throw new MojoFailureException("Generation failed, because of wrong exit code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            throw new MojoFailureException(e);
        }
    }
}
