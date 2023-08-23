cmake_minimum_required(VERSION 3.27)
project(JNI)

find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})

include_directories(jni)

set(CMAKE_CXX_STANDARD 11)

add_library(JNI SHARED library.cpp
        miku_lib_common_Native_NativeUtil.h)
