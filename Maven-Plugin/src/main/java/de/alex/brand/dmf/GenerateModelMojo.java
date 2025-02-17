package de.alex.brand.dmf;

import org.apache.maven.plugin.AbstractMojo;
import org.apache.maven.plugin.MojoExecutionException;
import org.apache.maven.plugin.MojoFailureException;
import org.apache.maven.plugin.logging.Log;
import org.apache.maven.plugins.annotations.LifecyclePhase;
import org.apache.maven.plugins.annotations.Mojo;
import org.apache.maven.plugins.annotations.Parameter;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.util.Scanner;

@Mojo(name = "generate-model", defaultPhase = LifecyclePhase.GENERATE_SOURCES)
public class GenerateModelMojo extends AbstractMojo {

    @Parameter(defaultValue = "./src/gen/java/")
    public String directory;

    @Parameter(defaultValue = "./target/dmf/install")
    public String installDirectory;

    @Override
    public void execute() throws MojoExecutionException, MojoFailureException {
        Log log = getLog();
        log.info("Preparing Generator");
        File generatorFile = prepareGenerator();

        generate(log, generatorFile);

    }

    protected void generate(Log log, File generatorFile) throws MojoExecutionException, MojoFailureException {
        log.info("Generating Model into " + directory);
        ProcessBuilder processBuilder = new ProcessBuilder(generatorFile.getAbsolutePath(), "--help");

        processBuilder.redirectErrorStream(true);
//        processBuilder.inheritIO();

        try {
            Process process = processBuilder.start();

            try (Scanner scanner = new Scanner(process.getInputStream())) {
                log.info("Read input stream");
                while (scanner.hasNextLine()) {
                    log.info(scanner.nextLine());
                }
            }
            int exitCode = process.waitFor();
            log.info("Generator exited with code " + exitCode);
        } catch (IOException | InterruptedException e) {
            throw new MojoFailureException(e);
        }


    }

    protected File prepareGenerator() throws MojoExecutionException, MojoFailureException {
        File file = new File(getGeneratorUsePath());
        if (file.exists()) {
            return file;
        }
        file.getParentFile().mkdirs();
        try {
            InputStream resource = this.getClass().getResourceAsStream("/" + getGeneratorName());
            Files.copy(resource, file.toPath());
        } catch (IOException e) {
            throw new MojoFailureException("Can't find Generator to copy",e);
        }
        return file;
    }

    protected String getGeneratorUsePath() {
        if (installDirectory == null) {
            installDirectory = "./";
        }
        if (!installDirectory.endsWith("/")) {
            installDirectory += "/";
        }
        return installDirectory+getGeneratorName();
    }

    protected String getGeneratorName() {
        return "javaGenerator.exe";
    }
}
