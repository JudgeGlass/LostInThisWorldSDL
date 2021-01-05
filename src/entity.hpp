#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Entity{
    public:
        virtual void render(SDL_Renderer *renderer) = 0;
        virtual void update() = 0;
    private:

    protected:
        int x;
        int y;
};

#endif