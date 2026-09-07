cmake_minimum_required(VERSION 3.10.2)
project("globus_core")

add_library(
        globus_core
        SHARED
        core_main.cpp
        globus_ui.cpp
)

find_library(
        log-lib
        log
)

target_link_libraries(
        globus_core
        ${log-lib}
        android
        GLESv2
)
