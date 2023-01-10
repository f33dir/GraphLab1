#include <iostream>
#include <vector>
#include "ImGui/imgui.h"
#include "SDL.h"
#include "ImGui/backends/imgui_impl_sdlrenderer.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "Engine/Application.h"
int main() {
    Application app;
    app.Run();
}

// (рендерер, формат цвета пикселя, флаги, размеры(x, y))


