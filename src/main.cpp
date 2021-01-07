#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "game.hpp"

/*
    Lost In This World
    Copyright (c) 2020-2021 Hunter Wilcox
                            Zicron Technologies

    THIS APPLICATION IS NOT INTENDED TO BE "FREE" SOFTWARE. IF YOU HAVE OBTAINED A COPY OF THE 
    FOLLOWING SOURCE CODE, PLEASE DELETE AND DO NOT DISTRIBUTE.

    Requirements:
        - SDL 2
        - SDL_Image
        - std=c++17
*/

// Where is all began...
int main(int argv, char** args){
    std::string title = "Lost In This World";
    Game game(800, 480, title);
    game.init();
    game.loop();

    return 0;
}