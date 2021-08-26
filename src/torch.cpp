#include "torch.hpp"

Torch::Torch(int x, int y, Texture *entityTextures, Player *player, int burnTime){
    this->x = x;
    this->y = y;
    this->entityTextures = entityTextures;
    this->player = player;
    this->burnTime = burnTime;
    collider = new AABB(x, y-12, 16, 24, TORCH);
    fireTile = new AnimatedTile(fireTextureIndex, 2, 10, entityTextures);
    torchLit = false;
}

void Torch::update(){
    collider->updatePos(worldXOffset, worldYOffset);

    if(torchLit){
        fireTile->update();
        tickCount++;
    }



    if(tickCount % (burnTime * 60) == 0){
        tickCount = 0;
        torchLit = false;
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