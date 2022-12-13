cmake_minimum_required(VERSION 3.23)
project(Lab)
file(GLOB ImGui
        "ImGui/*.h"
        "ImGui/*.cpp"
        "ImGui/backends/imgui_impl_sdlrenderer.*"
        "ImGui/backends/imgui_impl_sdl.*"
        )
file(GLOB engine
        "Engine/*.*"
        "Engine/*/*.*")
set(CMAKE_CXX_STANDARD 23)
find_package(SDL2 REQUIRED)
include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})
add_executable(Lab main.cpp ${ImGui}  ${engine} )
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

        