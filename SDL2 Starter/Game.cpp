//
//  Game.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 03.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "Game.h"

Game* Game::instance= 0 ;

bool Game::init(const char* title, int x, int y, int width, int height, int flags) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error initializing SDL" << endl;
        return false;
    }
    
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    
    if(window == nullptr) {
        SDL_Quit();
        cout << "Error creating window" << endl;
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if(renderer == nullptr) {
        SDL_Quit();
        cout << "Error creating renderer" << endl;
        return false;
    }
    
    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        cout << "SDL_image initialization failed" << endl;
        return false;
    }
    
    if(TTF_Init() != 0) {
        SDL_Quit();
        cout << "SDL_ttf initialization failed" << endl;
        return false;
    }
    
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4092) == -1) {
        SDL_Quit();
        cout << "SDL_mixer initialization failed" << endl;
        return false;
    }
    
    return true;
}


void Game::render() {

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

void Game::update() {
    
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            exit();
        }
    }
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::exit() {
    running = false;
}





























