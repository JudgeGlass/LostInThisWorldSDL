#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "aabb.hpp"
#include "animatedtile.hpp"

class Player{
    public:
        Player();
        ~Player();
        void setPos(int x, int y);
        void render(SDL_Renderer *renderer);
        void update(int xoff, int yoff);
        bool checkCollision(AABB &b1, AABB &b2);

        int xOffset = 0;
        int yOffset = 0;

        AABB *collider;
    private:
        
        int x;
        int y;
        
};


#endif