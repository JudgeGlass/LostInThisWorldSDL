#ifndef WORLD_HPP
#define WORLD_HPP

#include <SDL2/SDL.h>

class World{
    public:
        World();
        void render(SDL_Renderer *renderer);
        void update();
    private:
        //Player
};

#endif