#include "player.hpp"

Player::Player(Texture *entityTextures){
    this->entityTextures = entityTextures;
    collider = new AABB(368, 268, 32, 32, 2);

    animatedTile = new AnimatedTile(sprites, 2, 10, entityTextures);
}

void Player::render(SDL_Renderer *renderer){
    collider->render(renderer);
    animatedTile->render(renderer, 368, 268, 4);
}


void Player::update(int xoff, int yoff){
    animatedTile->update();


    for(auto &e: entities){
        e->onTrigger(collider);
    }
}

bool Player::checkCollision(AABB &b1, AABB &b2) {
    if(b1.getLeft() < b2.getRight() && b1.getRight() > b2.getLeft() && b1.getTop() < b2.getBottom() && b1.getBottom() > b2.getTop()) {
        return true;
    }
    return false;
}


void Player::setPos(int x, int y){
    this->x = x;
    this->y = y;
}

Player::~Player(){
    delete collider;
    delete animatedTile;
}