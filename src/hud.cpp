#include "hud.hpp"

HUD::HUD(Texture *fontTextures, Texture *entityTextures){
    this->fontTextures = fontTextures;
    this->entityTextures = entityTextures;
}


void HUD::update(){

}


void HUD::render(SDL_Renderer *renderer){
    std::string text = "Lost_In_This_World_SDL";
    drawString(7, 7, text, 0x000000, 2, fontTextures, renderer);
    drawString(5, 5, text, 0xFFFFFF, 2, fontTextures, renderer);
    
    std::string txt_fps = "FPS: " + std::to_string((int)fps);
    drawString(5, 20, txt_fps, 0xFFFFFFF, 2, fontTextures, renderer);

    drawInventory(renderer);
}

void HUD::drawInventory(SDL_Renderer *renderer){
    for(auto const&[item, amount] : inventory){
        switch (item)
        {
        case KEY:
            entityTextures->render(renderer, 4, 5, 50, 2, 32);
            drawString(21, 52, std::to_string(amount), 0xFFFFFF, 1, fontTextures, renderer);
            break;
        
        default:
            break;
        }
    }
}

bool HUD::addToInventory(Entity *e, int amount){
    for (auto const& [key, val] : inventory){
        
    }
}