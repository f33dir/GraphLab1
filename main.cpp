#include <iostream>
#include <vector>
#include "ImGui/imgui.h"
#include "SDL/include/SDL.h"
int main() {
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        std::cout << "Hello, World!" << std::endl;
    SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if(!window)
        return 0;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    int textureWidth = 500;
    int textureHeight = 500;
// (рендерер, формат цвета пикселя, флаги, размеры(x, y))
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET, textureWidth, textureHeight);


    int programworks;

    int fps = 60;
    Uint64 trueFrameTime = 1000.f / fps; // 16 ms
    while(true)
    {


        Uint64 frameTime = SDL_GetTicks(); // текущее значение в миллисекундах


        std::vector<Uint32> bufferForUpdate(textureWidth * textureHeight);
        for (auto& pixel: bufferForUpdate)
            pixel = 0xff000000; // RGBA = {255, 0, 0, 0}
        SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));

        frameTime = SDL_GetTicks() - frameTime;
        if (frameTime < trueFrameTime)
            SDL_Delay(trueFrameTime - frameTime);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void HandleInputs()
{
    SDL_Event e;

}