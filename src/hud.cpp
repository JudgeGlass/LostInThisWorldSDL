#include "hud.hpp"

HUD::HUD(Texture *fontTextures){
    this->fontTextures = fontTextures;
}


void HUD::update(){

}
void HUD::render(SDL_Renderer *renderer){
    std::string text = "Lost_In_This_World_SDL";
    drawString(7, 7, text, 0x000000, 2, fontTextures, renderer);
    drawString(5, 5, text, 0xFFFFFF, 2, fontTextures, renderer);
    
}