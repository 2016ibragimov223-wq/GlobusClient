// language: C++, file: app/src/main/cpp/core_main.cpp, target: Android ARM64, NDK
#include <jni.h>
#include <unistd.h>
#include <sys/mman.h>
#include <android/log.h>
#include "../../../include/offsets.h"
#include "memory.h"

#define LOG_TAG "GLOBUS_CORE"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_vanta_launcher_OverlayBridge_RunEngineLoop(JNIEnv* env, jobject thiz, jlong base_addr, jint screen_w, jint screen_h) {
    uintptr_t libBase = static_cast<uintptr_t>(base_addr);
    
    uintptr_t pm_base = SafeRead<uintptr_t>(libBase + Offsets::base::player_manager());
    if (!pm_base) return;

    uintptr_t p1 = SafeRead<uintptr_t>(pm_base + Offsets::manager::ptr1());
    uintptr_t p2 = SafeRead<uintptr_t>(p1 + Offsets::manager::ptr2());
    uintptr_t p3 = SafeRead<uintptr_t>(p2 + Offsets::manager::ptr3());
    
    uintptr_t localPlayer = SafeRead<uintptr_t>(p3 + Offsets::manager::local());
    uintptr_t entityList = SafeRead<uintptr_t>(p3 + Offsets::manager::list());
    int listSize = SafeRead<int>(p3 + Offsets::manager::list_size());

    if (!localPlayer || !entityList) return;

    uintptr_t buffer = SafeRead<uintptr_t>(entityList + Offsets::list::buffer());
    int stride = Offsets::list::stride();

    for (int i = 0; i < listSize; i++) {
        uintptr_t entry = SafeRead<uintptr_t>(buffer + Offsets::list::entry() + (i * stride));
        if (!entry || entry == localPlayer) continue;

        unsigned char team = SafeRead<unsigned char>(entry + Offsets::player::team());
        unsigned char localTeam = SafeRead<unsigned char>(localPlayer + Offsets::player::team());
        
        if (team == localTeam) continue;

        uintptr_t skeleton = SafeRead<uintptr_t>(entry + Offsets::player::skeleton());
        uintptr_t headNode = SafeRead<uintptr_t>(skeleton + Offsets::skeleton::head());
        uintptr_t transformObj = SafeRead<uintptr_t>(headNode + Offsets::skeleton::transform_object());
        uintptr_t matrixList = SafeRead<uintptr_t>(transformObj + Offsets::skeleton::matrix_list());
        Vector3 headPos = SafeRead<Vector3>(matrixList + Offsets::skeleton::matrix_ptr());

        LOGI("Globus Target Head -> X: %f, Y: %f, Z: %f", headPos.x, headPos.y, headPos.z);
    }
}
