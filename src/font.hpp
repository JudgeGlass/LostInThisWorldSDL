#ifndef FONT_HPP
#define FONT_HPP

#include <string>
#include <algorithm>
#include "texture.hpp"

static std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ      0123456789.,!?'\"-+=/\\%()<>:;_     " ;

static void drawString(int x, int y, std::string text, int color, int scale, Texture *fontTexture, SDL_Renderer *renderer){
    int r = (color & 0xFF0000) >> 16;
	int g = (color & 0xFF00) >> 8;
	int b = (color & 0xFF);

    SDL_SetTextureColorMod(fontTexture->texture, r, g, b);

    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    for(int i = 0; i < text.length(); i++){
        int index = chars.find((char)text[i]);
        if(index >= 0){
            fontTexture->render(renderer, index, x + i * (fontTexture->pw * scale), y, scale, 32);
        }
    }
}


#endif