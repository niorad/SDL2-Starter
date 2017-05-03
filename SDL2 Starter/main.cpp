#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

using namespace std;


int main(int argc, char **agv) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error initializing SDL" << endl;
        return 1;
    }

    
    SDL_Window *window = SDL_CreateWindow(
                                          "SDL2-Starter",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640,
                                          480,
                                          SDL_WINDOW_SHOWN);

    if(window == nullptr) {
        SDL_Quit();
        cout << "Error creating window" << endl;
        return 1;
    }
    

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        SDL_Quit();
        cout << "Error creating renderer" << endl;
        return 1;
    }

    
    SDL_RenderSetLogicalSize(renderer, 640, 480);
    
    
    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        cout << "SDL_image initialization failed" << endl;
        return 1;
    }
    
    
    if(TTF_Init() != 0) {
        SDL_Quit();
        cout << "SDL_ttf initialization failed" << endl;
        return 1;
    }
    
    
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4092) == -1) {
        SDL_Quit();
        cout << "SDL_mixer initialization failed" << endl;
        return 1;
    }
    
    SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    
    SDL_Delay(5000);
    
    SDL_Quit();
    
    return 0;
    
}








