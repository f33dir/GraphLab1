//
// Created by f33dir on 12/8/22.
//

#include "Application.h"

Application::Application(ApplicationConfig c) {

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        std::cout << "Hello, World!" << std::endl;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    window = SDL_CreateWindow(c.name, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, c.wight, c.height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    config = c;

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);

    size_t textureWidth = 500;
    size_t textureHeight = 500;
    texture = SDL_CreateTexture(renderer,
         SDL_PIXELFORMAT_RGBA8888,
         SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET,
         textureWidth,
         textureHeight);
    std::vector<Uint32> bufferForUpdate(textureWidth * textureHeight);
    for (auto& pixel : bufferForUpdate)
        pixel = 0xaa000000;
    SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
}

int Application::Run() {
    int fps = 60;
    Uint64 trueFrameTime = 1000.f / fps;
    while(programWorks)
    {
        Uint64 frameTime = SDL_GetTicks();
        HandleInputs();
        UpdateImage();
        frameTime = SDL_GetTicks() - frameTime;

        if (frameTime < trueFrameTime)
            SDL_Delay(trueFrameTime - frameTime);
    }
    return 0;
}

void Application::HandleImGui(){
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    // Render Gui
    {
        ImGui::Begin("Window");
        ImGui::End();
    }

    ImGui::Render();
}

void Application::HandleInputs() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        ImGui_ImplSDL2_ProcessEvent(&e);
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
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    // Render Gui
    {
        ImGui::Begin("Window");
        ImGui::End();
    }

    ImGui::Render();

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
}

Application::~Application() {
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

