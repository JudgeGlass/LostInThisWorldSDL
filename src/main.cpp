#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "game.hpp"

int main(int argv, char** args){
    std::string title = "Lost In This World";
    Game game(800, 480, title);
    game.init();
    game.loop();

    return 0;
}