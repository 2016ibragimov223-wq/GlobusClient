// language: C++, file: app/src/main/cpp/memory.h, target: Android ARM64, NDK
#pragma once
#include <stdint.h>

struct Vector3 { float x, y, z; };
struct Vector2 { float x, y; };

template <typename T>
T SafeRead(uintptr_t address) {
    if (!address) return T{};
    __try {
        return *reinterpret_cast<T*>(address);
    } __except (1) {
        return T{};
    }
}
