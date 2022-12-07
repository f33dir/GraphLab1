cmake_minimum_required(VERSION 3.23)
project(Lab)
file(GLOB ImGui
        "ImGui/*.h"
        "ImGui/*.cpp"
        "ImGui/backends/imgui_impl_sdlrenderer.*"
        "ImGui/backends/imgui_impl_sdl.*"
        )
set(CMAKE_CXX_STANDARD 23)
#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
add_executable(Lab main.cpp ${ImGui})
add_subdirectory(SDL)
target_link_libraries(${PROJECT_NAME}
#        ${SDL2_LIBRARIES}
        SDL2main SDL2-static
        )