cmake_minimum_required(VERSION 3.16)
project(DynaBlaster CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE AND EXISTS "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")
    set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")
endif()
find_package(SFML 2 REQUIRED COMPONENTS graphics window system audio)

add_library(Logging STATIC Logging/Logger.cpp)
target_include_directories(Logging PUBLIC Logging)

set(GAME_SOURCES
    DynaBlaster/Button.cpp
    DynaBlaster/DynaBlasterGame.cpp
    DynaBlaster/Enemy.cpp
    DynaBlaster/Player.cpp
    DynaBlaster/Source.cpp
    DynaBlaster/Map.cpp)
add_executable(DynaBlaster ${GAME_SOURCES})
target_include_directories(DynaBlaster PRIVATE DynaBlaster Logging)
target_link_libraries(DynaBlaster PRIVATE Logging sfml-graphics sfml-window sfml-system sfml-audio)
