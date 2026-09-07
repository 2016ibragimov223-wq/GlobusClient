// language: C++, file: app/src/main/cpp/globus_ui.cpp, target: Android ARM64, NDK
#include <jni.h>
#include <GLES2/gl2.h>
#include <android/log.h>

#define LOG_TAG "GLOBUS_UI"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

struct GlobusConfig {
    bool espBox = true;
    bool espSkeleton = true;
    bool silentAim = true;
    bool radarHack = true;
};

GlobusConfig g_Config;

extern "C" JNIEXPORT void JNICALL
Java_com_vanta_launcher_OverlayBridge_RenderGlobusUI(JNIEnv* env, jobject thiz) {
    LOGI("Globus Client Gradient Menu Frame Rendered.");
}
