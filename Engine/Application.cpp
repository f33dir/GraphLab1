//
// Created by f33dir on 12/8/22.
//

#include "Application.h"

Application::Application(ApplicationConfig c) {
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        std::cout << "Hello, World!" << std::endl;
    SDL_Window* window = SDL_CreateWindow(c.name, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, c.wight, c.height, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    config =c;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);
}

int Application::Run() {
    while(programWorks){
        HandleInputs();
        UpdateImage();
    }
}



void Application::HandleInputs() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case(SDL_QUIT):
                programWorks = false;
                break;
            case(SDL_KEYDOWN):
                keysPressed.insert(e.key.keysym.scancode);
                break;
            case(SDL_KEYUP):
                keysPressed.erase(e.key.keysym.scancode);
                break;
            case(SDL_MOUSEMOTION):
                mouseMovement = e;
                break;
            case(SDL_MOUSEBUTTONDOWN):
                mouseDown = e;
                break;
            case(SDL_MOUSEBUTTONUP):
                mouseUp = e;
        }
    }
}

void Application::UpdateImage() {

}