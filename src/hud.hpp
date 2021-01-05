#ifndef HUD_HPP
#define HUD_HPP

#include <SDL2/SDL.h>
#include "texture.hpp"
#include "font.hpp"

class HUD{
    public:
        HUD(Texture *fontTextures);
        void update();
        void render(SDL_Renderer *renderer);
    private:
        Texture *fontTextures;
};

#endif