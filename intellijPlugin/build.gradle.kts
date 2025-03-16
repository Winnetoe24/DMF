

plugins {
  id("java") // Java support
  id("org.jetbrains.kotlin.jvm") version "1.9.25"
  id("org.jetbrains.intellij.platform") version "2.3.0"
//  alias(libs.plugins.kotlin) // Kotlin support
//  alias(libs.plugins.intelliJPlatform) // IntelliJ Platform Gradle Plugin
//  alias(libs.plugins.changelog) // Gradle Changelog Plugin
//  alias(libs.plugins.qodana) // Gradle Qodana Plugin
//  alias(libs.plugins.kover) // Gradle Kover Plugin
}

group = "de.alex-brand"
version = "1.0-SNAPSHOT"

repositories {
  mavenCentral()

  // IntelliJ Platform Gradle Plugin Repositories Extension - read more: https://plugins.jetbrains.com/docs/intellij/tools-intellij-platform-gradle-plugin-repositories-extension.html
  intellijPlatform {
    defaultRepositories()
  }
}

//// Configure Gradle IntelliJ Plugin
//// Read more: https://plugins.jetbrains.com/docs/intellij/tools-gradle-intellij-plugin.html
//intellij {
//  version.set("2024.1.7")
//  type.set("IC") // Target IDE Platform
//
//  plugins.set(listOf(/* Plugin Dependencies */))
//}

tasks {
  // Set the JVM compatibility versions
  withType<JavaCompile> {
    sourceCompatibility = "17"
    targetCompatibility = "17"
  }
//  withType<org.jetbrains.kotlin.gradle.tasks.KotlinCompile> {
//    kotlinOptions.jvmTarget = "17"
//  }

  patchPluginXml {
    sinceBuild.set("241")
    untilBuild.set("243.*")
  }

  signPlugin {
    certificateChain.set(System.getenv("CERTIFICATE_CHAIN"))
    privateKey.set(System.getenv("PRIVATE_KEY"))
    password.set(System.getenv("PRIVATE_KEY_PASSWORD"))
  }

  publishPlugin {
    token.set(System.getenv("PUBLISH_TOKEN"))
  }
}

dependencies {
  intellijPlatform {
    intellijIdeaCommunity("2024.1")

//    bundledPlugin("com.intellij.java")
    plugin("com.redhat.devtools.lsp4ij", "0.11.0")
  }
}
