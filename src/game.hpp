#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Game{
    public:
        Game(int width, int height, std::string &title);
        void init();
        void handleEvents();
        void render();
    private:
        int width;
        int height;
        std::string title;
        SDL_Window *window;
};

#endif