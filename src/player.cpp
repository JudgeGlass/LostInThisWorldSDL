#include "player.hpp"

Player::Player(){
    //this->world = world;
    collider = new AABB(368, 268, 32, 32, 2);
}

void Player::render(SDL_Renderer *renderer){
    collider->render(renderer);
}

int counter = 0;
void Player::update(int xoff, int yoff){
    if(counter % 60 == 0){
        
        counter = 0;
    }

    counter++;
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
}