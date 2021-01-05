#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Entity{
    public:
        virtual void render(SDL_Renderer *renderer) {};
        virtual void update() {};
    private:

    protected:
        int x;
        int y;
};

#endif