cmake_minimum_required(VERSION 3.10)
project(MSH_M6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M6)

target_link_libraries(MSH_M6 PUBLIC MSH_M5)

target_include_directories(MSH_M6
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        
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
