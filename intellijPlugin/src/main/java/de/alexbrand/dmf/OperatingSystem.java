package de.alexbrand.dmf;
import java.util.Locale;

public enum OperatingSystem {
    WINDOWS,
    LINUX,
    MACOS;

    private static String osName = System.getProperty("os.name", "unknown").toLowerCase(Locale.ROOT);
    public static OperatingSystem OS;
    static {
        if (osName.contains("win")) {
            OS = WINDOWS;
        }else if (osName.contains("mac")) {
            OS = MACOS;
        }else if (osName.contains("nix") || osName.contains("nux") || osName.contains("aix")) {
            OS = LINUX;
        }
    }
    public static boolean isWindows()
    {
        return osName.contains("win");
    }

    public static boolean isMac()
    {
        return osName.contains("mac");
    }

    public static boolean isUnix()
    {
        return osName.contains("nux");
    }
}