#include "gate.hpp"

Gate::Gate(int x, int y, Texture *entityTextures, std::vector<AABB> *colliders, std::vector<Torch> torches){
    this->x = x;
    this->y = y;
    this->entityTextures = entityTextures;
    this->torches = torches;

    collider = new AABB(x*32, y*32, 16*6, 16, GATE);
    colliders->push_back(*collider);
}

void Gate::update(){
    for(auto &torch: torches){
        if(!torch.isLit()){
            break;
        }
    }
}

void Gate::render(SDL_Renderer *renderer){
    entityTextures->render(renderer, 43, (x*32) + worldXOffset, (y*32) + worldYOffset, 2, 32);
    entityTextures->render(renderer, 44, (x*32) + worldXOffset + 16, (y*32) + worldYOffset, 2, 32);
    entityTextures->render(renderer, 44, (x*32) + worldXOffset + 32, (y*32) + worldYOffset, 2, 32);
    entityTextures->render(renderer, 44, (x*32) + worldXOffset + 48, (y*32) + worldYOffset, 2, 32);
    entityTextures->render(renderer, 44, (x*32) + worldXOffset + 64, (y*32) + worldYOffset, 2, 32);
    entityTextures->render(renderer, 45, (x*32) + worldXOffset + 80, (y*32) + worldYOffset, 2, 32);
    collider->render(renderer);
}


void Gate::onTrigger(AABB *playerCollider){
    
}