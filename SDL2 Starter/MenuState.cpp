//
//  MenuState.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 05.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "MenuState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"

const string MenuState::menuID = "MENU";



void MenuState::update() {

}

void MenuState::render() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 0, 0, 0, 255);
}

bool MenuState::onEnter() {
    cout << "Entering MenuState" << endl;
    return true;
}


bool MenuState::onExit() {
    cout << "Exiting MenuState" << endl;
    return false;
}

void MenuState::onKeyDown(SDL_Event* e) {

}

void MenuState::onKeyUp(SDL_Event* e) {

}

void MenuState::onMouseButtonDown(SDL_Event& e) {

}

void MenuState::onMouseButtonUp(SDL_Event& e) {

}

void MenuState::onMouseMove(SDL_Event& e) {

}

