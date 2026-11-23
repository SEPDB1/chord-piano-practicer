cmake_minimum_required(VERSION 3.24)

set(CMAKE_TOOLCHAIN_FILE
    "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING ""
)

project(ChordPracticer)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main
)

FetchContent_MakeAvailable(
    SDL3
)

find_package(FluidSynth REQUIRED)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Game.cpp
    src/Renderer.cpp
    src/KeyboardView.cpp
    src/KeyView.cpp
    src/KeyController.cpp
    src/KeyboardController.cpp
    src/AudioManager.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
    FluidSynth::libfluidsynth
)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3::SDL3>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)