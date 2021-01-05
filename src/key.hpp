#ifndef KEY_HPP
#define KEY_HPP

#include <SDL2/SDL.h>

#include "entity.hpp"
#include "game_vars.hpp"
#include "texture.hpp"

class Key : public Entity{
    public:
        Key(int x, int y, Texture *entityTextures);
        void render(SDL_Renderer *renderer);
        void update();
    private:
        Texture *entityTextures;
};

#endif