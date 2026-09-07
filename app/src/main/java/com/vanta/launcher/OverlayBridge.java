// language: Java, file: app/src/main/java/com/vanta/launcher/OverlayBridge.java, target: Android
package com.vanta.launcher;

public class OverlayBridge {
    static {
        System.loadLibrary("globus_core");
    }

    public static native void RunEngineLoop(long baseAddr, int width, int height);
    public static native void RenderGlobusUI();
}
