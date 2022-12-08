#include <iostream>
#include <vector>
#include "ImGui/imgui.h"
#include "SDL.h"
#include "ImGui/backends/imgui_impl_sdlrenderer.h"
#include "ImGui/backends/imgui_impl_sdl.h"

void HandleInputs();

void UpdateImage();

bool programWorks =true;
int main() {

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        std::cout << "Hello, World!" << std::endl;
    SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if(!window)
        return 0;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    int textureWidth = 500;
    int textureHeight = 500;
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET, textureWidth, textureHeight);
    std::vector<Uint32> bufferForUpdate(textureWidth * textureHeight);
    SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);
    for (auto& pixel: bufferForUpdate)
        pixel = 0xff000000; // RGBA = {255, 0, 0, 0}
    int fps = 60;
    Uint64 trueFrameTime = 1000.f / fps; // 16 ms
    while(programWorks)
    {
        Uint64 frameTime = SDL_GetTicks(); // текущее значение в миллисекундах
        HandleInputs();
        UpdateImage();
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        frameTime = SDL_GetTicks() - frameTime;
        if (frameTime < trueFrameTime)
            SDL_Delay(trueFrameTime - frameTime);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void UpdateImage() {

}

void HandleInputs() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) // закрытие окна
            programWorks = false;

    }
}

// (рендерер, формат цвета пикселя, флаги, размеры(x, y))


