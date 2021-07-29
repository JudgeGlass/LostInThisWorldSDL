#include "torch.hpp"

Torch::Torch(int x, int y, Texture *entityTextures, Player *player){
    this->x = x;
    this->y = y;
    this->entityTextures = entityTextures;
    this->player = player;
    collider = new AABB(x, y-12, 16, 24, TORCH);
    fireTile = new AnimatedTile(fireTextureIndex, 2, 10, entityTextures);
    torchLit = false;
}

void Torch::update(){
    collider->updatePos(worldXOffset, worldYOffset);

    if(torchLit){
        fireTile->update();
    }
}

void Torch::render(SDL_Renderer *renderer){
    if(torchLit){
        fireTile->render(renderer, x + worldXOffset, y + worldYOffset - 12, 2);
    }
    entityTextures->render(renderer, 36+64, x + worldXOffset, y + worldYOffset, 2, 32);
    
    
}

void Torch::onTrigger(AABB *playerCollider){
    if(player->checkCollision(*playerCollider, *collider)){
        torchLit = true;
    }
}

bool Torch::isLit(){
    return torchLit;
}

Torch::~Torch(){
    delete fireTile;
    delete collider;
}