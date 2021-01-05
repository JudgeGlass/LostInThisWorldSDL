#include "key.hpp"


Key::Key(int x, int y, Texture *entityTextures){
    this->entityTextures = entityTextures;
    this->x = x;
    this->y = y;
}

void Key::render(SDL_Renderer *renderer){
    entityTextures->render(renderer, 4, x + worldXOffset, y + worldYOffset, 2, 32);
}

void Key::update(){

}