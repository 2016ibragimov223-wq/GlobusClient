// language: C++, file: include/offsets.h, target: Android ARM64, NDK
#pragma once
#include <stdint.h>

template <typename T> constexpr T oxorany(T val) { return val; }

namespace Offsets {
    namespace base {
        inline uint64_t player_manager() { return oxorany(180740496); }
    }
    namespace manager {
        inline int ptr1()       { return oxorany(0x90); }
        inline int ptr2()       { return oxorany(0x10); }
        inline int ptr3()       { return oxorany(0x0); }
        inline int local()      { return oxorany(0x70); }
        inline int list()       { return oxorany(0x28); }
        inline int list_size()  { return oxorany(0x20); }
    }
    namespace list {
        inline int buffer()     { return oxorany(0x18); }
        inline int entry()      { return oxorany(0x30); }
        inline int stride()     { return oxorany(0x18); }
    }
    namespace player {
        inline int team()       { return oxorany(0x79); }
        inline int skeleton()   { return oxorany(0x48); }
    }
    namespace skeleton {
        inline int transform_object()    { return oxorany(0x10); }
        inline int matrix_ptr()          { return oxorany(0x28); }
        inline int matrix_list()         { return oxorany(0x18); }
        inline int head()                { return oxorany(0x20); }
    }
    namespace aim {
        inline int aim_controller()     { return oxorany(0x80); }
        inline int aiming_data()        { return oxorany(0x90); }
        inline int aim_pitch_target()   { return oxorany(0x24); }
        inline int aim_yaw_target()     { return oxorany(0x28); }
    }
}
