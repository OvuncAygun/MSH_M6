cmake_minimum_required(VERSION 3.10)
project(MSH_M6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Creates the library for Module 6 
add_library(MSH_M6)

target_include_directories(MSH_M6
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external
    PRIVATE
        src
)

target_sources(MSH_M6
    PRIVATE
        # List all your implementation files here 
        src/MSH_M6.cpp
        src/SecurityManager.cpp
        src/EmergencyHandler.cpp
        src/AlarmAction.cpp
        src/LightBlinkAction.cpp
        src/PoliceCallAction.cpp
        src/FireStationAction.cpp
        src/SecurityChainBuilder.cpp
    
    PUBLIC
        # List the public headers others need to see
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M6.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ISecurityManager.h
)

include(CTest)
enable_testing()
