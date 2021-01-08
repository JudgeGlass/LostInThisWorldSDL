#ifndef HUD_HPP
#define HUD_HPP

#include <map>
#include <cassert>
#include <SDL2/SDL.h>
#include "texture.hpp"
#include "font.hpp"
#include "entity.hpp"

class HUD{
    public:
        HUD(Texture *fontTextures, Texture *entityTextures);
        void update();
        void render(SDL_Renderer *renderer);
        bool addToInventory(Entity *e, int amount);
    private:
        Texture *fontTextures;
        Texture *entityTextures;

        std::map<Entity*, int> inventory[8];
};

#endif