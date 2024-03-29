#include "map.hpp"

Map::Map(int x, int y, Texture *entityTextures, Player *player){
    this->x = x;
    this->y = y;
    this->entityTextures = entityTextures;
    this->player = player;
    collider = new AABB(x, y, 16, 16, MAP);
}

void Map::update(){
    collider->updatePos(worldXOffset, worldYOffset);
}

void Map::render(SDL_Renderer *renderer){
    entityTextures->render(renderer, 42, x + worldXOffset, y + worldYOffset, 2, 32);
}

void Map::onTrigger(AABB *playerCollider){
    if(player->checkCollision(*player->collider, *collider)){
        if(inventory.find(MAP) == inventory.end()){
            inventory[MAP] = 1;
        }else{
            inventory.find(MAP)->second++;
        }
        sound->playSound("sound/pickup2.wav");
        removeEntity(this);
    }
}

Map::~Map(){
    delete collider;
}