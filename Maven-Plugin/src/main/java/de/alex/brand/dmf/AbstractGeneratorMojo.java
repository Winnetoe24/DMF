package de.alex.brand.dmf;

import org.apache.maven.model.Resource;
import org.apache.maven.plugin.AbstractMojo;
import org.apache.maven.plugin.MojoExecutionException;
import org.apache.maven.plugin.MojoFailureException;
import org.apache.maven.plugin.logging.Log;
import org.apache.maven.plugins.annotations.Parameter;
import org.apache.maven.project.MavenProject;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.util.Scanner;

public abstract class AbstractGeneratorMojo extends AbstractMojo {
    @Parameter(defaultValue = "./target/generated-sources/dmf/")
    public String tempSources;

    @Parameter(defaultValue = "${pom.build.sourceDirectory}")
    public String sources;

    @Parameter(defaultValue = "./target/dmf/install")
    public String installDirectory;

    @Parameter(defaultValue = "${project}")
    private MavenProject project;

    @Parameter
    public String modelPath;

    @Parameter(defaultValue = "java")
    public String zielsprache;

    @Override
    public void execute() throws MojoExecutionException, MojoFailureException {
        Log log = getLog();
        log.info("Preparing Generator");
        File generatorFile = prepareGenerator();
        if (Zielsprache.JAVA == getZielsprache()) {
            project.addCompileSourceRoot(tempSources);
        }else {
            Resource resource = new Resource();
            if (this instanceof GenerateModelMojo) {
                resource.setDirectory(sources);
            }else {
                resource.setDirectory(tempSources);
            }
        }
        generate(log, generatorFile);

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
            throw new MojoFailureException("Can't find Generator to copy", e);
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
        return installDirectory + getGeneratorName();
    }

    protected String getGeneratorName() {
        if (OperatingSystem.isUnix()) {
            return "generator";
        }
        if (OperatingSystem.isWindows()) {
            return "generator.exe";
        }
        throw new RuntimeException("Unsupported Operating System");
    }

    protected abstract void generate(Log log, File generatorFile) throws MojoExecutionException, MojoFailureException;

    protected enum LogMode {
        INFO,
        ERROR,
    }

    protected MojoExecutionException processOutput(Log log, Process process) {
        MojoExecutionException mojoExecutionException = null;
        try (Scanner scanner = new Scanner(process.getInputStream())) {
            GenerateModelMojo.LogMode mode = GenerateModelMojo.LogMode.INFO;
            StringBuilder errorLine = new StringBuilder("\n");
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                if (line.startsWith("panic:")) {
                    mode = GenerateModelMojo.LogMode.ERROR;
                    mojoExecutionException = new MojoExecutionException("Es kam zu einem Fehler bei der Generation:" + line.substring("panic:".length()));
                } else if (line.startsWith("Generate")) {
                    mode = GenerateModelMojo.LogMode.INFO;
                }else if (line.startsWith("FehlerStelle")) {
                    mode = GenerateModelMojo.LogMode.ERROR;
                }
                if (mode == LogMode.INFO) {
                    log.info(line);
                } else {
                    log.error(line);
                    if (mojoExecutionException == null) {
                        errorLine.append(line).append("\n");
                    }
                }

            }
            if (errorLine.length() > 1) {
                mojoExecutionException = new MojoExecutionException(errorLine.toString());
            }
        }
        return mojoExecutionException;
    }


    protected Zielsprache getZielsprache() {
        return Zielsprache.valueOf(this.zielsprache.toUpperCase());
    }

}
