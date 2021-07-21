#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "game.hpp"

/*
    Lost In This World
    Copyright (c) 2020-2021 Hunter Wilcox
                            Zicron Technologies

    Requirements:
        - SDL 2
        - SDL_Image
        - std=c++17
*/

// Where is all began...
int main(int argv, char** args){
    const std::string GAME_VERSION = "0.0.2_1a";

    std::string title = "Lost In This World - v" + GAME_VERSION;
    Game game(800, 480, title);
    game.init();
    game.loop();

    return 0;
}