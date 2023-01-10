//
// Created by f33dir on 12/8/22.
//

#ifndef LAB_APPLICATION_H
#define LAB_APPLICATION_H
#include <iostream>
#include <vector>
#include "../ImGui/imgui.h"
#include "SDL.h"
#include "../ImGui/backends/imgui_impl_sdlrenderer.h"
#include "../ImGui/backends/imgui_impl_sdl.h"
#include "ApplicationConfig.h"
#include <set>
class Application {
private:
    bool programWorks =true;
    SDL_Window* window;
    SDL_Renderer* renderer;
    void HandleInputs();
    void UpdateImage();
    SDL_Texture* texture;
public:
    ApplicationConfig config;
    int xOffset;
    int yOffset;
    set<Uint8> keysPressed;
    SDL_Event mouseMovement;
    SDL_Event mouseDown;
    SDL_Event mouseUp;
    Application(ApplicationConfig config  = ApplicationConfig());
    ~Application();
    int Run();

    void HandleImGui();
};


#endif //LAB_APPLICATION_H
