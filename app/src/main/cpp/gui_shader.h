// language: C++, file: app/src/main/cpp/gui_shader.h, target: Android ARM64, NDK
#pragma once

const char* kVertexShader = 
    "attribute vec4 a_position;\n"
    "attribute vec4 a_color;\n"
    "varying vec4 v_color;\n"
    "void main() {\n"
    "   gl_Position = a_position;\n"
    "   v_color = a_color;\n"
    "}\n";

const char* kFragmentShader = 
    "precision mediump float;\n"
    "varying vec4 v_color;\n"
    "void main() {\n"
    "   gl_FragColor = v_color;\n"
    "}\n";
