#include "key.hpp"


Key::Key(int x, int y, Texture *entityTextures, Player *player){
    this->entityTextures = entityTextures;
    this->player = player;
    this->x = x;
    this->y = y;
    collider = new AABB(x, y, 18, 16, KEY);
}

void Key::render(SDL_Renderer *renderer){
    entityTextures->render(renderer, 4, x + worldXOffset, y + worldYOffset, 2, 32);
    collider->render(renderer);
}

void Key::update(){
    collider->updatePos(worldXOffset, worldYOffset);

    if(player->checkCollision(*player->collider, *collider)){
        removeEntity(this);
    }
}

Key::~Key(){
    delete collider;
}