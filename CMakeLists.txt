cmake_minimum_required(VERSION 3.23)
project(Lab)
file(GLOB ImGui
        "ImGui/*.h"
        "ImGui/*.cpp"
        "ImGui/backends/imgui_impl_sdlrenderer.*"
        "ImGui/backends/imgui_impl_sdl.*"
        )
set(CMAKE_CXX_STANDARD 23)
add_executable(Lab main.cpp ${ImGui} SDL/include/SDL3/SDL.h )
target_link_libraries(${PROJECT_NAME})

        