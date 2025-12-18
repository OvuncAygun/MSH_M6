cmake_minimum_required(VERSION 3.10)
project(MSH_M6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M6)

add_library(EXTERNAL INTERFACE)

target_include_directories(EXTERNAL
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/external
)

target_include_directories(MSH_M6
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        EXTERNAL
        
    PRIVATE
        src
)

target_sources(MSH_M6
    PRIVATE
        src/MSH_M6.cpp
        src/SecurityManager.cpp
        src/EmergencyHandler.cpp
        src/AlarmAction.cpp
        src/LightBlinkAction.cpp
        src/PoliceCallAction.cpp
        src/FireStationAction.cpp
        src/SecurityChainBuilder.cpp
        src/ISecurityManager.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M6.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ISecurityManager.h
)

include(CTest)
enable_testing()
