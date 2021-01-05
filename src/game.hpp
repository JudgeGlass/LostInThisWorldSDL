#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <direct.h>

#include "texture.hpp"
#include "world.hpp"
#include "game_vars.hpp"

class Game{
    public:
        Game(int width, int height, std::string &title);
        ~Game();
        void init();
        void loop();
        void handleEvents();
        void render();
        bool quit;

    private:
        int width;
        int height;
        std::string title;
        SDL_Window *window;
        SDL_Renderer *renderer;
        World *world;
};

#endif