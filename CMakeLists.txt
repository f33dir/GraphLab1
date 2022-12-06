cmake_minimum_required(VERSION 3.23)
project(Lab)
file(GLOB ImGui
        "*/*.h"
        "*.h"
        "*.cpp"
        "*/*.cpp"
        )
set(CMAKE_CXX_STANDARD 23)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
add_executable(Lab main.cpp ${ImGui} SDL)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})