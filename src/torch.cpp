#include "torch.hpp"

Torch::Torch(int x, int y, Texture *entityTextures, Player *player){
    this->x = x;
    this->y = y;
    this->entityTextures = entityTextures;
    this->player = player;
}

void Torch::update(){

}

void Torch::render(SDL_Renderer *renderer){

}

void Torch::onTrigger(AABB *playerCollider){

}

bool Torch::isLit(){
    return torchLit;
}