#ifndef HUD_HPP
#define HUD_HPP

#include <cassert>
#include <SDL2/SDL.h>
#include <string>
#include "texture.hpp"
#include "font.hpp"
#include "entity.hpp"
#include "game_vars.hpp"

class HUD{
    public:
        HUD(Texture *fontTextures, Texture *entityTextures);
        void update();
        void render(SDL_Renderer *renderer);
        bool addToInventory(Entity *e, int amount);
        void drawInventory(SDL_Renderer *renderer);
        void drawInventoryItem(int index, int tile, int amount, SDL_Renderer *renderer);
    private:
        Texture *fontTextures;
        Texture *entityTextures;

        
};

#endif